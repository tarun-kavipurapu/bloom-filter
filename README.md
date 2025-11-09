### 2. Install Dependencies
Use `vcpkg` to install the required dependencies:
```bash
./vcpkg/vcpkg install
```

### 3. Configure the Project
Create a build directory and configure the project using CMake:
```bash
mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake ..
```

### 4. Build the Project
Build the project using `make`:
```bash
make
```

### 5. Run the Executable
Run the compiled executable:
```bash
./bloom_filter
```