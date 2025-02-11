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

8. **Count Total Words or Characters**:
   - Count the total number of words or Characters in the document.

9. **Word Suggestion**:
   - Provide word suggestions as the user types.
   - Suggestions are updated after every character is typed.
   - Suggestions are stored in a `suggestion.txt` file, which can be modified by the user.

10. **Save Text**:
    - Save the current text in a `Given_Name.txt` file.

11. **Similarity Checker**:
    - Compare two `Given_Name.txt` files and check their similarity using an algorithm.

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

## 🛠️ Tools & Technologies Used

- **Programming Language**: C++
- **Development Environment**: Microsoft Visual Studio
- **Key Concepts Implemented**:
  - **Linked List**: Efficient insertion and deletion operations in the Notepad.
  - **Binary Search Tree (BST)**: Efficient storage and retrieval of word suggestions.
  - **Stack**: Used for undo functionality.
  - **File Handling**: For saving File Content
  - **Proper Code Indentation**: Improves readability


## 📸 Some Outputs
- ![image](https://github.com/user-attachments/assets/c7d00ea8-14cd-46b9-b2af-2f7c6ba7e5fd)
- ![image](https://github.com/user-attachments/assets/b6675117-8dcb-40f1-89b8-1d495c18e27d)
- **Write Text in Notepad**
 - ![image](https://github.com/user-attachments/assets/f8536df9-ff2a-4499-a95b-8bc1fb62839f)
- **After Display Text in Note Pad**
 - ![image](https://github.com/user-attachments/assets/c89bc3af-78cc-4a1f-830e-e93dcbefb88b)
- **After Deleting “ Good “ in Note Pad**
 - ![image](https://github.com/user-attachments/assets/8831782e-ceb4-49fd-b668-2f9a8588fd12)
- **After Undo**
 - ![image](https://github.com/user-attachments/assets/72f28af9-b833-4655-adb5-bc8cc4841104)
- **After Replace word “Good “ with “haid”**
 - ![image](https://github.com/user-attachments/assets/4461e4c6-868e-4d86-a238-1c4504fcec40)
- **Total Character in Note pad**
 - ![image](https://github.com/user-attachments/assets/c20108e5-9072-473e-9785-2a0a2e25ce11)
- **Take Suggestion of word**
 - ![image](https://github.com/user-attachments/assets/10f08cf4-235b-4eaa-bdcc-744ca0e09b01)
- **Update New suggestion**
 - ![image](https://github.com/user-attachments/assets/a98eea8f-634f-47bd-8ada-08540f6db052)
- **After Delete suggestion**
 - ![image](https://github.com/user-attachments/assets/d25fc786-73d7-4a43-8358-4a83eacb1503)
- **After Insert Suggestion In Note Pad**
 - ![image](https://github.com/user-attachments/assets/dab43a21-1b91-45d6-bc48-c81160070131)
- **After Save Data of Note Pad**
 - ![image](https://github.com/user-attachments/assets/9ceec1d9-0425-4b4a-9af5-e4e8534fc97d)
 - ![image](https://github.com/user-attachments/assets/0fab6706-fe2e-463c-8fbe-d121b651be5b)
- **After Copy Data From Note Pad**
 - ![image](https://github.com/user-attachments/assets/3d90b1e0-732b-4253-b33d-3dbfccf08cd8)
- **After Paste Data in Note Pad**
 - ![image](https://github.com/user-attachments/assets/8af5a0b6-b24b-4cc1-b2ca-c51410069d36)
- **Similarity in Two Files**
 - ![image](https://github.com/user-attachments/assets/b7603f75-f740-4b50-81a7-bcf84c957a6f)






