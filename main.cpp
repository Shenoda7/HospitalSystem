#include <bits/stdc++.h>

using namespace std;

const int MAX_SPECILIZATIONS = 20;
const int MAX_QUEUE = 5;

string names[MAX_SPECILIZATIONS + 1][MAX_QUEUE + 1];
int status[MAX_SPECILIZATIONS + 1][MAX_QUEUE + 1];
int queue_length[MAX_QUEUE + 1];

int menu(){
    int choice = -1;
    while(choice == -1){
        cout << "Enter your choice:\n";
        cout << "1) Add new patient\n";
        cout << "2) Print All patients\n";
        cout << "3) Get next patient\n";
        cout << "4) Exit\n";

        cin >> choice;

        if(!(1 <= choice && choice <= 4)){
            cout << "Invalid choice, please try again\n";
            choice = -1;
        }
    }
    return choice;
}

void shift_right(int spec, string names_sp[], int st_sp[]){
    int len = queue_length[spec];
    for(int i = len - 1; i >= 0; i--){
        names_sp[i + 1] = names_sp[i];
        st_sp[i + 1] = st_sp[i];
    }
    queue_length[spec]++;
}


void shift_left(int spec, string names_sp[], int st_sp[]){
    int len = queue_length[spec];
    for(int i = 1; i < len; ++i){
        names_sp[i - 1] = names_sp[i];
        st_sp[i - 1] = st_sp[i];
    }
    queue_length[spec]--;
}

bool add_patient(){
    int spec;
    int st;
    string name;

    cout << "Enter specialization, name, status\n";
    cin >> spec >> name >> st;

    int pos = queue_length[spec];
    if(pos >= MAX_QUEUE){
        cout << "Sorry we can't add more patients for this specialization\n";
        return false;
    }
    //if st is regular == 0;
    if(st == 0){
        names[spec][pos] = name;
        status[spec][pos] = st;
        queue_length[spec]++;
    }
    else {//if it's urgent we need to add it to the end
        shift_right(spec, names[spec], status[spec]);
        names[spec][0] = name;
        status[spec][0] = st;
    }

    return true;
}


void print_patient(int spec, string names_sp[], int st_sp[]){

    int len = queue_length[spec];
    if(len == 0){
        return;
    }
    cout << "There are " << len << " patients in specialization " << spec << "\n";
    for(int i = 0; i < len; ++i){
        cout << names_sp[i] << " ";
        if(st_sp[i] == 0){
            cout << "Regular\n";
        }
        else cout << "Urgent\n";
    }
    cout << "\n";
}
void print_all_patients(){
    cout << "**********************************\n";
    for(int spec = 0; spec < MAX_QUEUE; ++spec){
        print_patient(spec, names[spec], status[spec]);
    }
}

void get_nxt_patient(){
    int spec;
    cout << "Please enter specialization\n";
    cin >> spec;

    int len = queue_length[spec];
    if(len == 0){
        cout << "No patients at the moment. Have rest, Dr\n";
        return;
    }
    cout << names[spec][0] << " please go with the Dr\n";
    shift_left(spec, names[spec], status[spec]);
}

void hospital_system(){
    while(true){
        int choice = menu();

        if(choice == 1){
            add_patient();
        }
        else if(choice == 2){
            print_all_patients();
        }
        else if(choice == 3){
            get_nxt_patient();
        }
        else{
            break;
        }
    }
}


int main(){
    hospital_system();
    return 0;
}
