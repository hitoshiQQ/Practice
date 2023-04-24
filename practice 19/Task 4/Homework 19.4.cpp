#include <iostream>
#include <fstream>

bool isPng(const std::string& filename) {
    std::ifstream inFile(filename.c_str(), std::ios::binary);

    std::string fileType = filename.substr(filename.length() - 4);
    if (fileType != ".png" && fileType != ".PNG") return false;
    char fileNum;
    std::string fileChar;
    if (inFile.is_open()) {
        inFile >> fileNum;
        for (int i = 0; i < 3; ++i) {
            char tmp;
            inFile >> tmp;
            fileChar += tmp;
        }
        inFile.close();
    }
    else {
        std::cout << "File not found." << std::endl;
    }
    return (fileNum == -119 && fileChar == "PNG");
}

int main()
{
    std::cout<<"\t\tPNG-file detector\n\n";
    std::cout << "Enter the full file name: ";
    std::string fileName;
    std::cin >> fileName;
    std::cout << (isPng(fileName) ? "This is a png file" : "It is not a png file") << std::endl;

    return 0;
}

