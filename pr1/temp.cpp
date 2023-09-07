#include <iostream>

void fun1() {
    std::cout << "1\n";
}

void fun2() {
    std::cout << "2\n";
}

void fun3() {
    std::cout << "3\n";
    std::cout << "┌─────┬─────┐" << std::endl;
    std::cout << "│ Col1│ Col2│" << std::endl;
    std::cout << "├─────┼─────┤" << std::endl;
    std::cout << "│ Val1│ Val2│" << std::endl;
    std::cout << "├─────┼─────┤" << std::endl;
    std::cout << "│ Val3│ Val4│" << std::endl;
    std::cout << "└─────┴─────┘" << std::endl;

    std::cout << "╔═════╦═════╗" << std::endl;
    std::cout << "║ Col1║ Col2║" << std::endl;
    std::cout << "╟─────╢─────╢" << std::endl;
    std::cout << "║ Val1║ Val2║" << std::endl;
    std::cout << "╟─────╢─────╢" << std::endl;
    std::cout << "║ Val3║ Val4║" << std::endl;
    std::cout << "╚═════╩═════╝" << std::endl;
}

int main(int argc, char const *argv[]) {
    void (*arr[])() = {fun1, fun2, fun3};
    arr[2]();
    return 0;
}

/*
┌ └ ┐ ┘ ┼ ┬ ┴ ├ ┤ ─ │ 


╡ ╢ ╖ ╕ ╣ ║ ╗ ╝ ╜ ╛ ╞ ╟ ╚ ╔ ╩ ╦ ╠ ═ ╬ ╧ ╨ ╤ ╥ ╙ ╘ ╒ ╓ ╫ ╪ 

*/