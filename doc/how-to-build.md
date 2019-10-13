# How to build?

[中文版](how-to-build.zh-CN.md)

## 1. Windows

### 1.1 Prerequisites

1. Please make sure that you have __Visual Studio 2019__ or the higher. Because this is a VS2019 project.

2. Please make sure you have installed `vcpkg` and the following libraries: 

   * `mpir:x86-windows-static`
   * `mpir:x64-windows-static`

   is installed.

   You can install them by:

   ```console
   $ vcpkg install mpir:x86-windows-static
   $ vcpkg install mpir:x64-windows-static
   ```

3. Your `vcpkg` has been integrated into your __Visual Studio__, which means you have run 

   ```console
   $ vcpkg integrate install
   ```
   
   successfully.

### 1.2 Build

1. Open this project in __Visual Studio__.

2. Select `Release` configuration.

3. Select __Build > Build Solution__.

You will see executable file in `bin/` directory. 

## 2. Linux/macOS

### 2.1 Prerequisites

1. Please make sure you have following libraries:

   ```
   openssl
   mpir
   ```

   __If you use Ubuntu, you can install `openssl` and `mpir` via following commands:__

   ```bash
   # install openssl
   $ sudo apt-get install libssl-dev

   # install mpir
   $ wget http://mpir.org/mpir-3.0.0.tar.bz2
   $ tar -jxvpf ./mpir-3.0.0.tar.bz2
   $ cd mpir-3.0.0
   $ sudo apt-get install yasm      # yasm is required
   $ sudo apt-get install m4        # m4 is required
   $ ./configure --enable-cxx
   $ make
   $ make check
   $ sudo make install
   $ sudo ldconfig
   ```

   __If you use macOS, you can install `openssl` and `mpir` via following commands:__

   ```bash
   $ brew install openssl
   $ brew install mpir
   ```

### 2.2 Build

```bash
$ git clone https://github.com/DoubleLabyrinth/winrar-keygen.git
$ cd winrar-keygen
$ make keygen
```

Then you will see executable file in `bin/` directory.

