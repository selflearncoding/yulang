#include "Main.h"

auto main(int argc, char** argv)->int {
  string filePath = "main.yu";
  if (argc > 1) filePath = argv[1];
  string sourceCode = readSourceCodeFile(filePath);
  auto tokenList  = scan(sourceCode);
  auto syntaxTree = parse(tokenList);
  auto objectCode = generate(syntaxTree);
  execute(objectCode);
  system("pause");
  return 0;
}

auto readSourceCodeFile(string filePath)->string {
  ifstream file(filePath);
  if (file.fail() || file.is_open() == false) {
    cout << "Failed to open file: " << filePath << endl;
    system("pause");
    exit(1);
  }
  string sourceCode;
  getline(file, sourceCode, '\0');
  return sourceCode;
}
