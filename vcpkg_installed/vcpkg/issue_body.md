Package: zlib:x64-windows@1.3.1

**Host Environment**

- Host: x64-windows
- Compiler: MSVC 19.39.33523.0
-    vcpkg-tool version: 2025-02-11-bec4296bf5289dc9ce83b4f5095943e44162f9c2
    vcpkg-scripts version: d8f4a4703a 2025-02-25 (6 hours ago)

**To Reproduce**

`vcpkg install `

**Failure logs**

```
Downloading https://github.com/madler/zlib/archive/v1.3.1.tar.gz -> madler-zlib-v1.3.1.tar.gz
warning: Download https://github.com/madler/zlib/archive/v1.3.1.tar.gz failed -- retrying after 1000ms
warning: Download https://github.com/madler/zlib/archive/v1.3.1.tar.gz failed -- retrying after 2000ms
warning: Download https://github.com/madler/zlib/archive/v1.3.1.tar.gz failed -- retrying after 4000ms
error: https://github.com/madler/zlib/archive/v1.3.1.tar.gz: WinHttpSendRequest failed with exit code 12029. A connection with the server could not be established
note: If you are using a proxy, please ensure your proxy settings are correct.
Possible causes are:
1. You are actually using an HTTP proxy, but setting HTTPS_PROXY variable to `https//address:port`.
This is not correct, because `https://` prefix claims the proxy is an HTTPS proxy, while your proxy (v2ray, shadowsocksr, etc...) is an HTTP proxy.
Try setting `http://address:port` to both HTTP_PROXY and HTTPS_PROXY instead.
2. If you are using Windows, vcpkg will automatically use your Windows IE Proxy Settings set by your proxy software. See: https://github.com/microsoft/vcpkg-tool/pull/77
The value set by your proxy might be wrong, or have same `https://` prefix issue.
3. Your proxy's remote server is our of service.
If you believe this is not a temporary download server failure and vcpkg needs to be changed to download this file from a different location, please submit an issue to https://github.com/Microsoft/vcpkg/issues
CMake Error at scripts/cmake/vcpkg_download_distfile.cmake:124 (message):
  Download failed, halting portfile.
Call Stack (most recent call first):
  scripts/cmake/vcpkg_from_github.cmake:106 (vcpkg_download_distfile)
  C:/Users/XOAI/AppData/Local/vcpkg/registries/git-trees/3f05e04b9aededb96786a911a16193cdb711f0c9/portfile.cmake:2 (vcpkg_from_github)
  scripts/ports.cmake:196 (include)



```

**Additional context**

<details><summary>vcpkg.json</summary>

```
{
  "dependencies": [
    "sdl2",
    "sdl2-image",
    "fmt"
  ]
}

```
</details>
