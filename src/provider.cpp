#include "provider.h"

//default constructor
provider::provider(){
    name = "";
    street = "";
    city = "";
    state = "";
    zip = "";
    number = "";
    password = "";
}

//paramaterized constructor creates the object data members respectively from the string arguments
provider::provider(const string& name,const string& street,const string& city,const string& state,const string& zip,const string& number,const string& password){
    create(name,street,city,state,zip,number,password);
}

//copy constructor makes a deep copy of the member argument
provider::provider(const provider& toCopy){
    copy(toCopy);
}

//sets the object data members respectively from the string arguments
bool provider::create(const string& name,const string& street,const string& city,const string& state,const string& zip,const string& number,const string& password){
    this->name = name;
    this->street = street;
    this->city = city;
    this->state = state;
    this->zip = zip;
    this->number = number;
    this->password = password;
    return true;
}

//makes a deep copy of the member argument
bool provider::copy(const provider& toCopy){
    return create(toCopy.name,toCopy.street,toCopy.city,toCopy.state,toCopy.zip,toCopy.number,toCopy.password);
}

//displays provider information
void provider::display(){
    cout << "Provider Name:  " << name << endl;
    cout << "Provider #:     " << number << endl;
    cout << "Street Address: " << street << endl;
    cout << "City:           " << city << endl;
    cout << "State:          " << state << endl;
    cout << "Zip code:       " << zip << endl;
}

//verifies passed password returning boolean regarding match.
bool provider::isPassword(const string& toMatch)const{
    if(password.compare(toMatch) == 0)
        return true;
    return false;
}

//concatenates all strings together, delimiting each with "|", returns the new string
//used for writing to file, preformats
string provider::prepareWrite()const{
    string prep;
    prep = name;
    prep += "|";
    prep += street; 
    prep += "|";
    prep += city;
    prep += "|";
    prep += state;
    prep += "|";
    prep += zip;
    prep += "|";
    prep += number;
    prep += "|";
    prep += password;
    return prep;
}

//initializes a provider with a string generated by prepareWrite()
//used for deserializing from a file
istream &operator>>(istream &input, provider &toInit){
    getline(input, toInit.name, '|');
    getline(input, toInit.street, '|');
    getline(input, toInit.city, '|');
    getline(input, toInit.state, '|');
    getline(input, toInit.zip, '|');
    getline(input, toInit.number, '|');
    char passBuf[100];
    input.get(passBuf, 100, '|');
    toInit.password = passBuf;
    return input;
}

//checks that the argument matches the provider number and returns the respective boolean
bool provider::numberMatch(const string& toMatch)const{
    if(number.compare(toMatch) == 0)
        return true;
    return false;
}

//setter for name used for modification by CAC
void provider::setName(const string& name){
    this->name = name;
}

//setter for street used for modification by CAC
void provider::setStreet(const string& street){
    this->street = street;
}

//setter for city used for modification by CAC
void provider::setCity(const string& city){
    this->city = city;
}

//setter for state used for modification by CAC
void provider::setState(const string& state){
    this->state = state;
}

//setter for zip used for modification by CAC
void provider::setZip(const string& zip){
    this->zip = zip;
}

//setter for password used for modification by CAC
void provider::setPassword(const string& password){
    this->password = password;
}

//overloaded > operator compares name
bool provider::operator>(const provider& toCompare)const{
    if(name.compare(toCompare.name) > 0)
        return true;
    return false;
}

//overloaded < operator compares name
bool provider::operator<(const provider& toCompare)const{
    if(name.compare(toCompare.name) > 0)
        return false;
    return true;
}

//overloaded == operator compares number
bool provider::operator==(const provider& toCompare)const{
    if(number.compare(toCompare.number) == 0)
        return true;
    return false;
}
