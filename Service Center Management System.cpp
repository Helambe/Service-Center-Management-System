#include<iostream>
#include<ctime>
#include <regex> 
#include<ios>
#include<limits>
#define MAX 100
using namespace std;


struct car
{
    char *Name=NULL;
    long long int mobNum{0};
    const char *companyName=NULL;
    char *carNumber=NULL;
    const char *carDriveMode=NULL;
    const char *fuelType=NULL;
    float carFuelMileagePerLit{0};
    float calcMileage(float,int);
    float serviceTime{0};
    float serviceCostPerHour{0};
    float waitingTime{0};
    float bill(float,float);
    float hp{0};
    struct car *next=NULL;
    struct car *prev=NULL;

} *head=NULL,*bottom=NULL;

enum companyName
{
        Suzuki=1,
        Tata=2,
        RollsRoyce=3,
        Mercedez=4,
        BMW=5
};

enum fuelType
{
    Petrol=1,
    Diesel=2,
    CNG=3,
    Electric=4
};

enum driveMode
{
    FourWheelFront=1,
    FourWheelRare=2,
    TwoWheelFront=3,
    TwoWheelRare=4
};

int charArrayLength(char arr[])
{
    int i=0;
    while(arr[i]!='\0')
    {
        i++;
    }
    return i;
}

void charArrayCopy(char arr[],char temp[])
{
    for(int i=0;temp[i]!='\0';i++)
    {
        arr[i]=temp[i];
    }
}

void ownerName(struct car* var)
{
    char tempName[MAX];
    while(1)
    {
        cout<<"\nEnter your name :"<<endl;
        cin.getline(tempName,MAX);
        //cin.ignore();
        regex reg("([A-Za-z]+[ ]*)+");
        if (regex_match(tempName, reg)) 
        { 
            break; 
        } 
        cout<<"Invalid name\n";
    }
    var->Name=(char *)malloc(charArrayLength(tempName)*sizeof(char));
    charArrayCopy(var->Name,tempName);
}

void ownerMobileNumber(struct car* var)
{
    char tempMobNum[MAX];
    int value{0};
    while(1)
    {
        cout<<"\nEnter Your Mobile Number\n";
        cin.clear();
        cin.getline(tempMobNum,MAX);
        if(charArrayLength(tempMobNum)>10)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
        regex reg("[1-9][0-9]{9}");
        if (regex_match(tempMobNum, reg)) 
        { 
            int value=atoi(tempMobNum);
            var->mobNum=value;
            break; 
        } 
        }
        cout<<"Invalid mobile number\n";
    }
}

int carCompanyName(struct car* var)
{
    
    int flg{0};
    bool check=true;
    cout<<"\nNames of Car Company:\n";
    cout<<"1.Suzuki\t2.Tata\t3.RollsRoyce\n4.Mercedez\t5.BMW";
    while(check)
    {
        cout<<"\nChoose Company Name of Car: ";
        char chh[MAX];
        cin.getline(chh,MAX); 
        if(charArrayLength(chh)!=1)
        {
            cout<<"Invalid choice\n";
        }
        else
        {
        switch(atoi(chh))
        {
        case Suzuki: 
                var->companyName="Suzuki";
                var->serviceTime=1;
                var->serviceCostPerHour=2000;
                flg=1;
                check=false;
                break;

        case Tata:
                var->companyName="Tata";
                var->serviceTime=1.5;
                var->serviceCostPerHour=1700;
                flg=2;
                check=false;
                break;
        case RollsRoyce:
                var->companyName="RollsRoyce"; 
                var->serviceTime=2.5;
                var->serviceCostPerHour=1200;
                flg=3;
                check=false;
                break;
        case Mercedez:
                var->companyName="Mercedez";
                var->serviceTime=3;
                var->serviceCostPerHour=1500;
                flg=4;
                check=false;
                break;
        case BMW:
                var->companyName="BMW";
                var->serviceTime=3.5;
                var->serviceCostPerHour=1500;
                flg=5;
                check=false;
                break;
        default:
                cout<<"Invalid Choice\n";
        }
        }
    }
    return flg;
}

void carNumber(struct car* var)
{
    char tempCarNum[MAX];
    while(1)
        {
        cout<<"\nEnter car number[CCDDCCDDDD]c->character,D->digit:\n";
        cin.get(tempCarNum,MAX);
        cin.ignore();
        // Car number validiation
        regex reg("[A-Za-z]{2}[0-9]{2}[A-Za-z]{2}[0-9]{4}");
        if (regex_match(tempCarNum, reg)) 
        { 
            break; 
        } 
        cout<<"Invalid Car NUmber\n";
        }
        var->carNumber=(char*)malloc(charArrayLength(tempCarNum)*sizeof(char));
        charArrayCopy(var->carNumber,tempCarNum);

}

void hpValue(struct car* var,int flg)
{
    char tempHp[MAX];
    switch(flg)
    {
        char tempHp[MAX];
        case 1:
               while(1)
                {
                    cout<<"\nEnter HP value in range 100-110:"<<endl;
                    cin.getline(tempHp,MAX);
                    regex reg("[0-9]+[.|0-9][0-9]+");
                    //regex reg("[0-9|.]+");
                    // int count=0;
                    // for(int i=0;i<charArrayLength(tempHp);i++)
                    // {
                    //     if(tempHp[i]=='.')count++;
                    // }
                    if (regex_match(tempHp, reg)) //&& (count==1||count==0)) 
                    { 
                        float value=atof(tempHp);
                        if(100<value && value<110)
                        {
                            var->hp=value;
                            break;
                        }
                    }
                    cout<<"Invalid HP value\n";
                }
                break;
        case 2:
               while(1)
                {
                    cout<<"\nEnter HP value in range 90-100:"<<endl;
                    cin.getline(tempHp,MAX);
                    regex reg("[0-9]+[.|0-9][0-9]+");
                    if (regex_match(tempHp, reg)) 
                    { 
                        float value=atof(tempHp);
                        if(90<value && value<100)
                        {
                            var->hp=value;
                            break;
                        }
                    } 
                    cout<<"Invalid HP value\n";
                }
                break;
        case 3:
                while(1)
                {
                    cout<<"\nEnter HP value in range 85-90:"<<endl;
                    cin.getline(tempHp,MAX);
                    regex reg("[0-9]+[.|0-9][0-9]+");
                    if (regex_match(tempHp, reg)) 
                    { 
                        int value=atof(tempHp);
                        if(85<value && value<90)
                        {
                            var->hp=value;
                            break;
                        }
                    }
                    cout<<"Invalid HP value\n";
                }
                break;
        case 4:
                while(1)
                {
                    cout<<"\nEnter HP value in range 80-85:"<<endl;
                    cin.getline(tempHp,MAX);
                    regex reg("[0-9]+[.|0-9][0-9]+");
                    if (regex_match(tempHp, reg)) 
                    { 
                        int value=atof(tempHp);
                        if(80<value && value<85)
                        {
                            var->hp=value;
                            break;
                        }
                    }
                    cout<<"Invalid HP value\n";
                }
                break;
        case 5:
                while(1)
                {
                    cout<<"\nEnter HP value in range 70-80:"<<endl;
                    cin.getline(tempHp,MAX);
                    regex reg("[0-9]+[.|0-9][0-9]+");
                    if (regex_match(tempHp, reg)) 
                    { 
                        int value=atof(tempHp);
                        if(70<value && value<80)
                        {
                            var->hp=value;
                            break;
                        }
                    }
                    cout<<"Invalid HP value\n";
                }
    }
}

void driveMode(struct car* var)
{
    bool check=true;
    char chh[MAX];
    cout<<"\nDrive modes of car are:\n";
    cout<<"1.FourWheelFront\t2.FourWheelRare\n3.TwoWheelFront\t4.TwoWheelRare";
    while(check)
    {
    cout<<"\nChoice drive mode of your car:";
    cin.getline(chh,MAX);
    if(charArrayLength(chh)!=1)
    {
        cout<<"Invalid Choice";
    }
    else
    {
    switch(atoi(chh))
    {
        case FourWheelFront: 
                var->carDriveMode="FourWheelFront";
                check=false;
                break;
        case FourWheelRare:
                var->carDriveMode="FourWheelRare";
                check=false;
                break;
        case TwoWheelFront:
                var->carDriveMode="TwoWheelFront"; 
                check=false;
                break;
        case TwoWheelRare:
                var->carDriveMode="TwoWheelRare";
                check=false;
                break;
        default:
                cout<<"Invalid choice.\n";
    }
    }
    }
}

void fuelType(struct car* var)
{
    char chh[MAX];
    bool check=true;
    cout<<"\nFuel types of car:\n";
    cout<<"1.Petrol\t2.Diesel\n3.CNG\t\t4.Electric";
    while(check)
    {
    cout<<"\nChoose Fule type of Car: ";
    cin.getline(chh,MAX);
    if(charArrayLength(chh)!=1)
    {
            cout<<"Invalid choice\n";

    }
    else
    {
        switch(atoi(chh))
        {
            case Petrol: 
                    var->fuelType="Petrol";
                    var->carFuelMileagePerLit=34;
                    check=false;
                    break;
            case Diesel:
                    var->fuelType="Diesel";
                    var->carFuelMileagePerLit=26;
                    check=false;
                    break;
            case CNG:
                    var->fuelType="CNG";
                    var->carFuelMileagePerLit=30;
                    check=false;
                    break;
            case Electric:
                    var->fuelType="Electric";
                    var->carFuelMileagePerLit=45;
                    check=false;
                    break;
            default:
                    cout<<"Invalid choice\n";
        }
    }
    }
}

float car::calcMileage(float hp,int mileage)
{
    return 100*mileage/hp;
}

void carWaitingTime(struct car* var,int wCarNum)
{ 
    var->waitingTime=wCarNum*var->serviceTime;
}

void deliveryTime(float wTime)
{
    time_t now = time(0);
    int hr,mn,sec;

    char* date_time = ctime(&now);
    cout << "\nThe current date and time is: " << date_time ;
    struct tm tstruct = *localtime(&now);
    float f = tstruct.tm_hour + tstruct.tm_min / 60.0 + tstruct.tm_sec / 3600.0+wTime;
    //cout<<f<<endl;
    cout<<"Your car delivery time: ";
    hr=(int)f;
    mn=(int)((f-hr)*60);
    sec=(int)(((f-hr)*60-mn)*60);
    cout<<hr<<":"<<mn<<":"<<sec;
}

float car::bill(float sTime,float sCostPerHour)
{
    return sTime*sCostPerHour+0.09*(sTime*sCostPerHour)+0.09*(sTime*sCostPerHour); 
} 

void printDetails()
{
    cout<<"\n\nPrinting details of all cars:"<<endl;
    int i=0;
    struct car* temp=head;
    if(head==NULL)
    {
        cout<<"Car details not available";
        return;
    }
    while(temp!=NULL)
    {   
        cout<<"\n\n*** Details of car"<<++i<<" ***";
        cout<<"\nDear "<<temp->Name<<",";
        cout<<"\nContact number: "<<temp->mobNum;
        cout<<"\nCar company name: "<<temp->companyName;
        cout<<"\nCar number: "<<temp->carNumber;
        cout<<"\nCar driving mode: "<<temp->carDriveMode;
        cout<<"\nHP value: "<<temp->hp;
        cout<<"\nFuel type: "<<temp->fuelType;
        cout<<"\nMileage of car: "<<
        head->calcMileage(temp->hp,temp->carFuelMileagePerLit)<<"km/lit";
        cout<<"\nServicing time: "<<temp->serviceTime<<"hr";
        cout<<"\n-----------------------------";
        cout<<"\nBasic cost amount: ₹"<<temp->serviceTime*temp->serviceCostPerHour<<"/-";
        cout<<"\nSGST amount: ₹"<<0.09*temp->serviceTime*temp->serviceCostPerHour<<"/-";
        cout<<"\nCGST amount: ₹"<<0.09*temp->serviceTime*temp->serviceCostPerHour<<"/-";
        cout<<"\n-----------------------------";
        cout<<"\n\nTotal Amount: ₹"<<
        head->bill(temp->serviceTime,temp->serviceCostPerHour)<<"/-";
        cout<<"\n-----------------------------";
        cout<<"\nWaiting time: "<<temp->waitingTime<<"hr";
        deliveryTime(temp->waitingTime);
        cout<<"\n=============================================";
        temp=temp->next;
    }
    //cout<<carPtr[2].Name;
}

int main()
{
    int flag{0},wCarNum{0};
    int carNum[4]{0};
    char next;

    do
    {
        struct car *temp=head,*nCar;
        nCar=(struct car*)malloc(sizeof(struct car));

        if(head==NULL)
        {
            bottom=NULL;
            head=nCar;
        }
        else
        {
            bottom->next=nCar;
        }
        
        if(head==NULL)
        {
            cout<<"Memory is not allocated"<<endl;
        exit(0);
        }

        nCar->prev=bottom;
        
        // Accepting name of car owner
        //ownerName(nCar);
        
        // Accepting owner mobile number
        //ownerMobileNumber(nCar);

        // Choosing name of car company
        flag=carCompanyName(nCar);

        switch(flag)
        {
            case 1:  
                wCarNum=++carNum[0];
                break;     
            case 2:
                wCarNum=++carNum[1];
                break;     
            case 3:
                wCarNum=++carNum[2];
                break;     
            case 4:
                wCarNum=++carNum[3];
                break;     
            case 5:
                wCarNum=++carNum[4];
        }

        // Accepting car number
        //carNumber(nCar);
    
        // Enter hp value
        hpValue(nCar,flag);

        // Choosing drive mode of car
        driveMode(nCar);

        // Choosing fuel type
        fuelType(nCar);

        // Calculating waiting time of car          
        carWaitingTime(nCar,wCarNum);

        nCar->next=NULL;
        bottom=nCar;
               
    cout<<"\nDo you want to add one more car(Y/N)?"<<endl;
    cin>>next;
    cin.ignore();
    }while(next=='Y'||next=='y');

    // Printing details of car
    printDetails();

struct car* temp;
temp=head;
while(temp!=NULL) 
{
    free(temp);
    temp=temp->next;
}   

cout<<"\n\nThank You...!!!";
cout<<endl;

return 0;

}