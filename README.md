# Advanced Notepad using Data Structures(BST,Linked List,Huffman Coding)

This project is an advanced Notepad application implemented using various data structures. The program allows users to perform a variety of text manipulation operations, including inserting, deleting, searching, copying, pasting, and more. The application is designed to mimic the functionality of a basic text editor with additional features like word suggestions, undo functionality, and file comparison.

## Features

1. **Add Text**: 
   - Insert text at any specific position (x, y) in the document.
   - The user provides the position and the text to be inserted.

2. **Delete Text**:
   - Delete all occurrences of a specific string from the document.
   - The user provides the string to be deleted.

3. **Search Words**:
   - Search for a specific string in the document.
   - If the string is found, the program displays all positions where the string occurs.

4. **Copy Text**:
   - Copy a substring from the document by specifying the start (x1, y1) and end (x2, y2) positions.
   - The copied text is saved in a variable for later use.

5. **Paste Text**:
   - Paste the copied text at a specific position (x, y).
   - If text already exists at the position, the user is prompted to confirm whether they want to overwrite it.

6. **Find and Replace**:
   - Find a specific word in the document and replace it with another word.
   - The user can choose to replace only the first occurrence or all occurrences.

7. **Undo Text**:
   - Undo the last operation performed using a stack-based approach.
   - Each operation is saved in a stack, allowing the user to revert changes.

8. **Count Total Words**:
   - Count the total number of words in the document.

9. **Word Suggestion**:
   - Provide word suggestions as the user types.
   - Suggestions are updated after every character is typed.
   - Suggestions are stored in a `suggestion.txt` file, which can be modified by the user.

10. **Save Text**:
    - Save the current text in a `.txt` file.

11. **Similarity Checker**:
    - Compare two `.txt` files and check their similarity using an algorithm.

## Technologies and Tools

- **Programming Language**: C++
- **Data Structures**:
  - **Binary Search Tree (BST)**: For efficient word suggestion retrieval.
  - **Huffman Coding**: For compressing and providing fast access to word suggestions.
  - **Stack**: For undo functionality.
  - **Linked Lists**: For text manipulation.
- **Algorithms**:
  - **Text Search Algorithms**: For efficient text search and replacement.
  - **Text Similarity Algorithm**: For comparing text files.
    
## Files

- `Source.cpp`: The main source code file containing the implementation of the Notepad application.
- `suggestion.txt`: A text file containing initial word suggestions that can be updated by the user.
- `README.md`: This file, providing an overview of the project and instructions on how to use it.

## Requirements

- C++ compiler (e.g., `g++`).
- Basic understanding of data structures (e.g., linked lists, stacks,Huffman Coding,BST).
