#include <iostream>
#include <conio.h>

using namespace std;

class details_doctor1
{
    char doc_name[20], doc_Qualification[20], doc_age[20], doc_city[20], doc_special[20];
    int doc_id;

public:
    friend class doctor;      
    details_doctor1()       
    {
        this->doc_id = 0;        
    }
};

class details_patient1
{
    int pat_id1;
    char pat_name[20], pat_age[20], pat_city[20], pat_dis[20], pat_room[20], pat_bill[20];

public:
    friend class patient;
    details_patient1()
    {
        this->pat_id1 = 0;
    }
};

class hospital
{
public:
    int id;
    int counter;
    hospital()
    {

        this->id = 0;   
        this->counter = 0;
    }
};

class doctor : public hospital         
{
public:
    int docid;
    doctor()
    {
        this->docid = 0;
    }
    details_doctor1 arr[10];  
    void add_doc_info();      
    void Display();
    void doctor_detail();
    void tot_no_of_doc();
};

//define function
void doctor::add_doc_info()
{
    int i, ent;
    cout << "How Many Entries you want to add: ";
    cin >> ent;
    for (i = 1; i <= ent; i++)
    {
        cout << "Enter Doctor's ID                :";
        cin >> arr[docid].doc_id;                
        cout << "Enter Doctor's Name              :";
        cin >> arr[docid].doc_name;
        cout << "Enter Doctor's Age               :";
        cin >> arr[docid].doc_age;
        cout << "Enter Doctor's Qualification     :";
        cin >> arr[docid].doc_Qualification;
        cout << "Enter Doctor's Specialization    :";
        cin >> arr[docid].doc_special;
        cout << "Enter Doctor's city              :";
        cin >> arr[docid].doc_city;
        docid++;
        counter++;                  
        cout << "\n";
        cout << "You filled all Entries of " << i << " doctor successfully"
             << "\n";
        cout << "Enter value for " << i + 1 << " doctor"
             << "\n";
    }
}

void doctor::Display()              
{
    system("cls");              
    int n, i;
    cout << "Enter the doctor's ID  to display Record: ";
    cin >> n;
    if (n == 0)
    {
        cout << "\n\n                      OOPS!!!!             "
             << "\n\n";
        cout << "Note:-   No Record To Display Plz Go Back And Enter Some Entries..."
             << "\n";
    }
    else
    {
        int status = 0;
        for (i = 0; i < docid; i++)
        {
            if (arr[i].doc_id == n) 
            {
                status = 1;
                break;
            }
        }
        if (status) 
        {
            system("cls");
            cout << "1.Doctor's ID                 :" << arr[i].doc_id << "\n\n";
            cout << "2.Doctor's Name               :" << arr[i].doc_name << "\n\n";
            cout << "3.Doctor's Age                :" << arr[i].doc_age << "\n\n";
            cout << "4.Doctor's Qualification      :" << arr[i].doc_Qualification << "\n\n";
            cout << "5.Doctor's Specialization     :" << arr[i].doc_special << "\n\n";
            cout << "6.Doctor's city               :" << arr[i].doc_city << "\n\n";
            cout << "\nPress Any KEY To choose another Option...";
        }
        else
        {
            cout << "\n\nNo such ID in database " << endl;
            cout << "\nPress Any KEY To choose another Option...";
        }
    }
    getch();      
}

void doctor::doctor_detail()
{
    int i;
    if (docid == 0)
    {
        cout << "\n\n\n                                  OOPS!!!!             "
             << "\n\n";
        cout << "Note:-   No Record To Display  Plz Go Back And Enter Some Entries..."
             << "\n";
    }
    else
    {
        cout << "**************"
             << "\n";
        cout << "Details Of All The Doctors In The Hospital \n";
        cout << "**************"
             << "\n \n";

        cout << "ID"
             << "\t \t"
             << "specialization"
             << "\t \t"
             << "Qualification"
             << "\t \t"
             << "Age";
        cout << "\n \n";

      

        for (i = 0; i < docid; i++)
        {
            cout << arr[i].doc_id << "\t \t" << arr[i].doc_special << "\t \t \t" << arr[i].doc_Qualification << "\t  \t \t" << arr[i].doc_age << "\n";
        }
        cout << "\nPress Any Button To choose another Option...";
    }
    getch();
}

void doctor::tot_no_of_doc()
{
    system("cls");
    int i = counter;      
    cout << "Total Doctor's in Hospital: " << i << "\n";
    cout << "\nPress Any Button To choose another Option...";
    getch();
}

class patient : public hospital
{
    int patcounter=0;
public:
    int docid1 = 0;      
    details_patient1 arr[10];
    void add_pat_info();
    void Display();
    void patient_report();
    void patient_detail();
    void tot_no_of_pat();
    void get_patient_bill();
};

void patient::add_pat_info()
{
    int i, ent;
    hospital obj1;
    cout << "How Many Entries you want to add: ";
    cin >> ent;
    for (i = 1; i <= ent; i++)
    {
        cout << "1.Please Enter Patient's ID :                                 ";
        cin >> arr[docid1].pat_id1;
        cout << "2.Please Enter patient's Name :                               ";
        cin >> arr[docid1].pat_name;
        cout << "3.Please Enter patient's Age :                                ";
        cin >> arr[docid1].pat_age;
        cout << "4.Please Enter patient's Disease :                            ";
        cin >> arr[docid1].pat_dis;
        cout << "5.Please Enter Patient's Room No :                           ";
        cin >> arr[docid1].pat_room;
        cout << "6.Please Enter Patient's Medicine charge :                   ";
        cin >> arr[docid1].pat_bill;
        docid1++;
        obj1.counter++;
        cout << "\n";
        cout << "You filled all Entries of " << i << " patient successfully"
             << "\n";
        cout << "Enter value for " << i + 1 << " patient"
             << "\n";
    patcounter ++;
    }

}
void patient ::Display()
{
    system("cls");
    int n, i;
    cout << "\nEnter the Patient's ID to display info: ";
    cin >> n;
    if (n == 0)
    {
        cout << "\n\n                      OOPS!!!!             "
             << "\n \n";
        cout << "Note:-   No Record To Display  Plz Go Back And Enter Some Entries..."
             << "\n";
        cout << "\nPress Any KEY To choose another Option...";
    }
    else
    {
        int status = 0;
        for (i = 0; i < docid1; i++)
        {
            if (arr[i].pat_id1 == n)
            {
                status = 1;
                break;
            }
        }
        if (status == 1)
        {
            cout << "1.Patient's ID                                      :" << arr[i].pat_id1 << "\n";
            cout << "2.Patient's Name                                    :" << arr[i].pat_name << "\n";
            cout << "3.Patient's Age                                     :" << arr[i].pat_age << "\n";
            cout << "4.Patient's  Disease                                :" << arr[i].pat_dis << "\n";
            cout << "6.Patient's Room No.                                :" << arr[i].pat_room << "\n";



            cout << "7.Patient's Medicine charge                        :" << arr[i].pat_bill << "\n";
            cout << "\nPress Any KEY To choose another Option...";
        }
        else
        {
            cout << " \n\n No such ID in database " << endl;
            cout << " \n Press Any KEY To choose another Option...";
        }
    }
    getch();
}

void patient ::patient_report()
{
    system("cls");
    int i, n;
    cout << "\nEnter the Patient's ID to Display  Report: ";
    cin >> n;
    int status = 0;
    for (i = 0; i < docid1; i++)
    {
        if (arr[i].pat_id1 == n)
        {
            status = 1;
            break;
        }
    }
    if (status)
    {
        cout << "------------------------------------------" << endl;
        cout << "Patient's Report"
             << "\n";
        cout << "------------------------------------------" << endl
             << endl;
        cout << "1. Patient's Name: " << arr[i].pat_name << "\n";
        cout << "2. Patient's Age: " << arr[i].pat_age << "\n";
        cout << "3. Patient Disease: " << arr[i].pat_dis << "\n";


        cout << "Press Any Key To Go Back...";
    }
    else
    {
        cout << " \n\n No such ID in database " << endl;
        cout << " \n Press Any KEY To choose another Option...";
    }

    getch();
}

void patient ::patient_detail()
{
    int i;
    if (docid1 == 0)
    {
        cout << " \n\n\n\n\n                                  OOPS!!!!             "
             << "\n\n\n";
        cout << "Note:-   No Record To Display  Plz Go Back And Enter Some Entries...... "
             << "\n";
    }
    else
    {
        cout << "**************"
             << "\n";
        cout << "\t \t \t\t\t  Details Of All The Pateint In The Hospital \n";
        cout << "**************"
             << "\n \n";
        cout << "ID"
             << "\t \t"
             << "illness"
             << "\t \t"
             << "       Age";
        cout << "\n \n";
        for (i = 0; i < docid1; i++)
        {
            cout << arr[i].pat_id1 << "\t \t" << arr[i].pat_dis << "\t \t \t"  << arr[i].pat_age << "\n";
        }
        cout << " \n Press Any KEY To choose another Option.... ";
    }
    getch();
}

void patient ::tot_no_of_pat()
{
    system("cls");
    cout << "Total Patients in Hospital    :   " << patcounter << "\n";      
    cout << "\nPress Any KEY To choose another Option.... ";
    getch();
}

void patient ::get_patient_bill()
{
    system("cls");
    int i, n;
    cout << "\nEnter the Patient's ID to Display Bill: ";
    cin >> n;
    int status = 0;
    for (i = 0; i < docid1; i++)
    {
        if (arr[i].pat_id1 == n)
        {
            status = 1;
            break;
        }
    }
    if (status)
    {
        cout << "------------------------------------------" << endl;
        cout << "Patient's Report"
             << "\n";
        cout << "------------------------------------------" << endl
             << endl;
        cout << "Patient's Medicine Charge: " << arr[i].pat_bill << "\n";
        cout << "Press Any Key To Go Back...";
    }

    else
    {
        cout << "\n\nNo such ID in database " << endl;
        cout << "\nPress Any KEY To choose another Option...";
    }
    getch();
}

int main()
{
    bool repeat = true;  
    int ch1, ch2, ch3, ch4; 
    doctor dr;           
    patient pt;
    goposition1:           
        system("cls");
        cout << "\t\t\t\t\t\t\tWELCOME TO                                             \n";
        cout << "\t\t\t\t                                                                                    \n";
        cout << "\t\t\t\t\t\tHOSPITAL MANAGEMENT SYSTEM                                  \n";

        cout << "Press any key to continue";
        getch();
        system("cls");
        cout << "\t\t\t\t\t------------------------------------------" << endl;
        cout << "\t\t\t\t\tWelcome to the Hospital Management System" << endl;
        cout << "\t\t\t\t\t------------------------------------------" << endl
             << endl;
        cout << "1. Menu"
             << "\n\n";
        ;
        cout << "2. Exit"
             << "\n\n";
        cout << "Enter Your Choice: ";
        cin >> ch1;

        if (ch1 == 1)
        {
        goposition2:                                
            system("cls");
            cout << "1.Enter into Doctor's DataBase" << endl
                 << endl;
            cout << "2.Enter into Patient's DataBase" << endl
                 << endl;
            cout << "3.Generate Patient's Report" << endl
                 << endl;
            cout << "4.Generate Patient's Bill" << endl
                 << endl;
            cout << "5.EXIT"
                 << "\n\n";
            cout << "Enter Your choice: ";
            cin >> ch2;
            while (repeat == true)
            {
                system("cls");
                switch (ch2)
                case 1:
                {
                    cout << "------------------------------------------" << endl;
                    cout << "Welcome To Doctor's DataBase"<<endl;
                    cout << "------------------------------------------" << endl
                         << endl;
                    cout << "1. Add New Doctor's Information" << endl
                         << endl;
                    cout << "2. Display Doctor's Information" << endl
                         << endl;
                    cout << "3. Detail OF ALL The Doctors In The Hospital" << endl
                         << endl;
                    cout << "4. Total Number of Doctor's  in Hospital" << endl
                         << endl;
                    cout << "5. EXIT"
                         << "\n\n";
                    cout << "Please Enter your choice :";
                    cin >> ch3;
                    switch (ch3)
                    {
                    case 1:
                        system("cls");
                        dr.add_doc_info();
                        break;
                    case 2:
                        dr.Display();
                        cout << "\n";
                        break;

                    case 3:
                        system("cls");
                        dr.doctor_detail();
                        break;

                    case 4:
                        dr.tot_no_of_doc();
                        break;

                    case 5:
                        exit(1);
                    default:
                        cout << "Invalid Input";
                    }
                    break;
                case 2:
                    system("cls");
                    cout << "------------------------------------------" << endl;
                    cout << "Welcome To Patient's DataBase" << endl;
                    cout << "------------------------------------------" << endl
                         << endl;
                    cout << "1. Add New Patient's Information" << endl
                         << endl;
                    cout << "2. Display Patient's Information" << endl
                         << endl;
                    cout << "3. Detail OF ALL The Patient In The Hospital" << endl
                         << endl;
                    cout << "4. Total Number of Patient's in Hospital" << endl
                         << endl;
                    cout << "5. EXIT"
                         << "\n\n";
                    cout << "Enter your choice: ";
                    cin >> ch4;
                    switch (ch4)
                    {
                    case 1:
                        system("cls");
                        pt.add_pat_info();
                        break;
                    case 2:
                        pt.Display();
                        cout << "\n";
                        break;

                    case 3:
                        system("cls");
                        pt.patient_detail();
                        break;

                    case 4:
                        pt.tot_no_of_pat();
                        break;

                    case 5:
                        goto goposition2;           
                        break;

                    default:
                        cout << "invalid";
                        break;
                    }
                    break;
                case 3:

                    pt.patient_report();
                    goto goposition2;      
                    break;
                case 4:
                    pt.get_patient_bill();
                    goto goposition2;
                    break;
                case 5:
                    goto goposition1;
                    break;
                }
            }
        }
        else if (ch1 == 2)     
        {
            system("cls");

            cout << "\t\t\t\t\t\tTHANK YOU FOR USING\n";
            cout << "\t\t\t\t\t\tHOSPITAL MANAGEMENT SYSTEM";

            return 0;
        }
        else
        {
            cout << "Wrong Input please try again!!!" << endl;

        }

    return 0;
}