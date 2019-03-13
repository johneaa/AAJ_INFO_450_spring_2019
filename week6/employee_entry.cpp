#include <iostream>
#include <cstdio>
using namespace std;

const int YEARLYWORKHOURS = 2000;

class EmployeeEntry {

private:
    char first_name[255]; // First Name
    char last_name[255]; // Last Name
    bool is_hourly; // Hourly/Annual
    char comp[7]; // Compensation
    
public:
    void set_first_name(char* in_name) {
        
        strcpy(first_name, in_name);
        
    }
    
    void set_last_name(char* in_name) {
        
        strcpy(last_name, in_name);
        
    }
    
    void set_is_hourly(bool is_hour) {
        
        is_hourly = is_hour;
        
    }
    
    void set_comp(char* in_comp) {
        
        strcpy(comp, in_comp);
        
    }
    
    void printEntry() {
        if (!is_hourly) {
            
        cout << last_name << ", ";
        cout << first_name << " : $";
        cout << comp << endl;
        }
       
        else if (is_hourly) {
            
        cout << last_name << ", ";
        cout << first_name << " : $";
        cout << atoi(comp) * YEARLYWORKHOURS << endl;
        }
    }
   
    };
int main()
{
    const int MAX = 3;
    
    //PhoneEntry entry;
    EmployeeEntry entries[MAX];
    
    // entry.set_first_name("Chris");
    // entry.set_middle_initial(' ');
    // entry.set_last_name( "Fauerbach");
    // entry.set_area_code( "804");
    // entry.set_phone_number( "5392443");
    // entry.set_is_private(  false );
    // entry.printEntry();
    for (int x = 0; x < MAX; x++) {
        cout << "Entry: " << x << endl;
        char *myvalue = (char *)malloc(255);
        
        
        cout << "Enter employee first name: ";
        cin.getline(myvalue, 255);
        entries[x].set_first_name(myvalue);
        
        cout << "Enter employee last name: ";
        cin.getline(myvalue, 255);
        entries[x].set_last_name(myvalue);
        
        cout << "Employee Type (Hourly/Exempt): ";
        cin.getline(myvalue, 7);
        while (strcmp(myvalue, "HOURLY") && (strcmp(myvalue, "EXEMPT"))) {
            
            cout << "Input is case-sensitive. Enter 'HOURLY' or 'EXEMPT'";
            cout << "Employee Type (Hourly/Exempt): ";
            cin.getline(myvalue, 7);
        }
        if (!strcmp(myvalue , "EXEMPT")) {
            
            cout << "Enter Annual Salary: ";
            cin.getline(myvalue, 7);
            entries[x].set_comp(myvalue);
            entries[x].set_is_hourly(false);
            
        }
        else if (!strcmp(myvalue , "HOURLY")) {
        
        cout << "Enter hourly rate: ";
        cin.getline(myvalue, 7);
        entries[x].set_comp(myvalue);
        entries[x].set_is_hourly(true);
            
        }
    }
    
    for (int x = 0; x < MAX; x++) {
        entries[x].printEntry();
    }
    
    return 0;
}
