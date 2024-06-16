#include <iostream>
#include <string>
using namespace std;
struct Note {
    string text;
    Note* next;
};

class NoteList {
public:
    NoteList() : head(nullptr) {}

    void addNote() {
        string noteText;
        cout << "Enter your note: ";
        cin.ignore();
        getline(cin, noteText);

        Note* newNote = new Note{ noteText, nullptr };

        if (head == nullptr) {
            head = newNote;
        } else {
            Note* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNote;
        }
        cout << "Note added successfully!" << endl;
    }

    void deleteNote() {
        if (head == nullptr) {
            cout << "No notes to delete." << endl;
            return;
        }

        int position;
        cout << "Enter the note number to delete: ";
        cin >> position;

        if (position == 1) {
            Note* temp = head;
            head = head->next;
            delete temp;
            cout << "Note deleted successfully!" << endl;
            return;
        }

        Note* temp = head;
        for (int i = 1; i < position - 1; ++i) {
            if (temp == nullptr || temp->next == nullptr) {
                cout << "Invalid position!" << endl;
                return;
            }
            temp = temp->next;
        }

        Note* noteToDelete = temp->next;
        if (noteToDelete == nullptr) {
            cout << "Invalid position!" << endl;
            return;
        }

        temp->next = noteToDelete->next;
        delete noteToDelete;
        cout << "Note deleted successfully!" << endl;
    }

    void viewNotes() const {
        if (head == nullptr) {
            cout << "No notes available." << endl;
            return;
        }

        Note* temp = head;
        int count = 1;
        while (temp != nullptr) {
            cout << count << ". " << temp->text << endl;
            temp = temp->next;
            ++count;
        }
    }

private:
    Note* head;
};

int main() {
    NoteList notes;
    int choice;

    do {
        cout << "Note Taking Application" << endl;
        cout << "1. Add Note" << endl;
        cout << "2. Delete Note" << endl;
        cout << "3. View Notes" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                notes.addNote();
                break;
            case 2:
                notes.deleteNote();
                break;
            case 3:
                notes.viewNotes();
                break;
            case 4:
                cout << "Exiting the application." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
