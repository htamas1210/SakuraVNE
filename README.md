# SakuraVNE
Visual novel creator engine made with SDL2

Clone the project:
`git clone https://github.com/htamas1210/SakuraVNE.git --recursive`

## windows:
Generate a visual studio 2026 solution and build from there:
`cmake -G "Visual Studio 18 2026" -A x64`

## linux:
`cmake -B build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON`
`ln -sf build/compile_commands.json compile_commands.json`
`cmake --build build -j`
