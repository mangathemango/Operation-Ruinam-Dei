#include <animation.h>
#include <stdlib.h>
#include <string.h>
#include <app.h>

Animation* Animation_Create(SDL_Texture* spritesheet) {
    Animation* animation = malloc(sizeof(Animation));
    animation->texture = spritesheet;
    animation->clips = NULL;
    animation->clipCount = 0;
    animation->currentClip = -1;
    animation->currentFrame = 0;
    animation->timer = 0.0f;
    animation->isPlaying = false;
    animation->direction = 1;
    return animation;
}

void Animation_Destroy(Animation* animation) {
    // Free clip names and frame arrays
    for (int i = 0; i < animation->clipCount; i++) {
        free(animation->clips[i].name);
        free(animation->clips[i].frames);
    }
    
    // Free clips array
    free(animation->clips);
    
    // Free animation struct
    free(animation);
}

void Animation_AddClip(Animation* animation, const char* name, 
                      AnimationFrame* frames, int frameCount, 
                      float frameDuration, bool looping) {
    // Expand clips array
    animation->clips = realloc(animation->clips, (animation->clipCount + 1) * sizeof(AnimationClip));
    
    // Get reference to new clip
    AnimationClip* clip = &animation->clips[animation->clipCount];
    
    // Copy name
    clip->name = strdup(name);
    
    // Allocate and copy frames
    clip->frames = malloc(frameCount * sizeof(AnimationFrame));
    memcpy(clip->frames, frames, frameCount * sizeof(AnimationFrame));
    
    // Set other properties
    clip->frameCount = frameCount;
    clip->frameDuration = frameDuration;
    clip->looping = looping;
    
    // Increment clip count
    animation->clipCount++;
}

AnimationFrame* Animation_GetFixedSizeFrames(SDL_Texture *texture, Vec2 frameSize, int frameNumbers) {
    Vec2 textureSize = {0,0};
    SDL_QueryTexture(texture, NULL, NULL, (int*)&textureSize.x,(int*)&textureSize.y);
    for (int x = 0; x < textureSize.x; x += frameSize.x) {
        for (int y = 0; y < textureSize.y; y += frameSize.y) {
            frameNumbers++;
        }
    }
}

// Find clip index by name
static int Animation_FindClipIndex(Animation* animation, const char* clipName) {
    for (int i = 0; i < animation->clipCount; i++) {
        if (strcmp(animation->clips[i].name, clipName) == 0) {
            return i;
        }
    }
    return -1;
}

void Animation_Play(Animation* animation, const char* clipName) {
    int clipIndex = Animation_FindClipIndex(animation, clipName);
    if (clipIndex < 0) return;
    
    // If already playing this clip, do nothing
    if (animation->currentClip == clipIndex && animation->isPlaying) {
        return;
    }
    
    animation->currentClip = clipIndex;
    animation->currentFrame = 0;
    animation->timer = 0.0f;
    animation->isPlaying = true;
    animation->direction = 1;
}

void Animation_Stop(Animation* animation) {
    animation->isPlaying = false;
    animation->currentFrame = 0;
    animation->timer = 0.0f;
}

void Animation_Pause(Animation* animation) {
    animation->isPlaying = false;
}

void Animation_Resume(Animation* animation) {
    animation->isPlaying = true;
}

void Animation_Update(Animation* animation, float deltaTime) {
    if (!animation->isPlaying || animation->currentClip < 0) {
        return;
    }
    
    AnimationClip* clip = &animation->clips[animation->currentClip];
    
    // Add time to timer
    animation->timer += deltaTime;
    
    // Check if it's time for next frame
    if (animation->timer >= clip->frameDuration) {
        animation->timer -= clip->frameDuration;
        
        // Move to next frame
        animation->currentFrame += animation->direction;
        
        // Handle end of animation
        if (animation->currentFrame >= clip->frameCount) {
            if (clip->looping) {
                animation->currentFrame = 0;
            } else {
                animation->currentFrame = clip->frameCount - 1;
                animation->isPlaying = false;
            }
        } else if (animation->currentFrame < 0) {
            if (clip->looping) {
                animation->currentFrame = clip->frameCount - 1;
            } else {
                animation->currentFrame = 0;
                animation->isPlaying = false;
            }
        }
    }
}

void Animation_Render(Animation* animation, SDL_Renderer* renderer, 
                     int x, int y, SDL_RendererFlip flip) {
    // Make sure we have a valid clip
    if (animation->currentClip < 0 || animation->currentClip >= animation->clipCount) {
        return;
    }
    
    // Get current clip and frame
    AnimationClip* clip = &animation->clips[animation->currentClip];
    AnimationFrame* frame = &clip->frames[animation->currentFrame];
    
    // Create source rectangle (area in the spritesheet)
    SDL_Rect srcRect = {
        frame->position.x, 
        frame->position.x, 
        frame->size.x, 
        frame->size.y       
    };
    
    // Create destination rectangle (where to render on screen)
    SDL_Rect dstRect = {
        x, 
        y, 
        frame->size.x, 
        frame->size.y
    };
    
    // Render the frame with the specified flip
    SDL_RenderCopyEx(
        renderer,
        animation->texture,
        &srcRect,
        &dstRect,
        0,      // No rotation
        NULL,   // No rotation center (default)
        flip    // Flip horizontally/vertically if needed
    );
}