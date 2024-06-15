#include <iostream>
#include <fstream>
#include <string>


//Function to append to file. Takes two parameters, the filename and the data.
void appendToFile(const std::string &filename, const std::string &data) {
    std::ofstream outfile; //Declare an output file stream objecy named outfile.
    outfile.open(filename, std::ios_base::app); // open file in append mode
    if (outfile.is_open()) { //Checks to see if the file is open.
        outfile << data << std::endl; //If it is write data to file followed by a newline.
        outfile.close(); //Close file.
    } else { //If the file cannot open notify user.
        std::cerr << "Unable to open file for appending!" << std::endl;
    }
}

//Function to reverse the contents of the CSC450_CT5_mod5.txt. Takes two parameters, the input file to read from and the output file to write to.
void reverseFileContent(const std::string &inputFile, const std::string &outputFile) {
    std::ifstream infile(inputFile); //Declares and input file stream object named infile and opens the file named inputFile
    if (!infile.is_open()) { //Check to see if file is open.
        std::cerr << "Unable to open input file!" << std::endl; //Print error message to user if file could not be opened.
        return;
    }

    std::string content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>()); //Reads the entire content of the file into the string named content.
    infile.close(); //Closes input file

    std::reverse(content.begin(), content.end()); //Reverse the content of the string content.

    std::ofstream outfile(outputFile); //Declares output file stream object outfile that opens the outputFile.
    if (outfile.is_open()) { //Checks to see if the output file was opened succesfully.
        outfile << content; //Writes the reveresed content to the output file.
        outfile.close(); //Closes file.
    } else {
        std::cerr << "Unable to open output file!" << std::endl; //Notifies user if the file cannot be opened.
    }
}

int main() {
    std::string userInput; //Creates a string variable named userInput to store user data.
    std::cout << "Enter the data you want to append to the file: ";
    std::getline(std::cin, userInput); //Grabs the line and saves it to userInput

    //Declares string filename with the file path of CSC450_CT5_mod5.txt saved on my machine.
    std::string filename = "/Users/cubbyevil/Documents/Aidan College/CSU/Courses/2024/Spring 2024/Term C/CSC450ProgrammingIII/Module 5/Critical Thinking/CSC450_CT5_mod5.txt";
    appendToFile(filename, userInput); //Appends userInput to file input.

    std::cout << "Data appended to file successfully!" << std::endl; //Lets user know the data was appended succesfully.

    // Reverse the content of the file
    std::string reversedFilename = "/Users/cubbyevil/Documents/Aidan College/CSU/Courses/2024/Spring 2024/Term C/CSC450ProgrammingIII/Module 5/Critical Thinking/CSC450-mod5-reverse.txt";
    reverseFileContent(filename, reversedFilename);

    std::cout << "File content reversed and saved to " << reversedFilename << " successfully!" << std::endl;

    return 0;
}
