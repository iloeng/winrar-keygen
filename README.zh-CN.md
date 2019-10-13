# WinRAR-Keygen

## 1. WinRAR是什么？

WinRAR是一款用于管理压缩包文件的共享软件。其算法由作者尤金·罗谢尔研发，享有原创专利。

它可以用来创建或浏览RAR、ZIP等众多格式的压缩包。

WinRAR不是免费的软件。如果你想使用它，你应当向[__RARLAB__](https://rarlab.com/)付费，然后获得一个授权文件 `rarreg.key`。

这份repo将会告诉你 `rarreg.key` 是如何生成的。

## 2. "rarreg.key"是如何生成的？

见[这里](doc/how-does-it-work.zh-CN.md)。

## 3. 如何编译？

该项目支持 __Windows__ 和 __Linux/macOS__ 平台。

请见[这里](doc/how-to-build.zh-CN.md)来完成编译。

PS: 感谢Multi提供unix的支持。

## 4. 如何使用？

```
Usage:
        winrar-keygen.exe <your name> <license type>

Example:

        winrar-keygen.exe "Rebecca Morrison" "Single PC usage license"
  or:
        winrar-keygen.exe "Rebecca Morrison" "Single PC usage license" > rarreg.key
```

```console
$ winrar-keygen.exe "DoubleLabyrinth" "Single PC usage license"
RAR registration data
DoubleLabyrinth
Single PC usage license
UID=d2fb7cb15c078a3def58
6412212250ef58bef21cdcb49ca34b7040112cae5a512f1adad1a8
f6d2ee8c382fe64f8e3d6035c6ab9048e2c5c62f0238f183d28519
aa87488bf38f5b634cf28190bdf438ac593b1857cdb55a7fcb0eb0
c3e4c2736090b3dfa45384e08e9de05c5860d3051942adf2db9d96
e2ec37f1cfae00b3e2455093b90e4e352f016f6b9853c735d45fb4
01f9cbb91d3f3ac5664511229f8c9b0a9e1d61a2e087b481607e91
bfc8a83414f6807d31a5f8c587513aa54f9b1249ad804214409316
```

