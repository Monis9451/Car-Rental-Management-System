#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string admin_id = "admin";
string admin_pass = "0000";
int no_of_cus = 0;
int no_of_cars = 0;
int no_of_rented_cars = 0;
int rentes_car_details = 0;
struct cars
{
	string name;
	string model;
	string color;
	string top_speed;
	string fuel_avg;
	int price_rentPerDay;
};
struct customer_data
{
	string name;
	string pass;
	string phone;
	string address;
};
struct rented_car
{
	string cname;
	string name;
	string model;
	string color;
	string top_speed;
	string fuel_avg;
	int price_rentPerDay;
};
struct rented_detail
{
	string cus_name;
	string car_name;
	int rent_days;
	int bill;
	string date;
};

void login();
void admin_menu();
void customer_menu();
void rent_a_car();
void return_a_car();
void available_cars();
void rental_report();
void Logout();
void change_pass();
void view_current_avlbl_car();
void update_customer_data();
void add_or_remove_cus();
void add_or_remove_car();
void all_reports();
void update_car();


int main()
{
	string st;
	ofstream output_cus("customer.txt",ios::app);
	ifstream input_cus("customer.txt");
	while (getline(input_cus, st))
	{
		no_of_cus++;
	}
	ofstream output_cars("cars.txt",ios::app);
	ifstream input_cars("cars.txt");
	while (getline(input_cars, st))
	{
		no_of_cars++;
	}
	ofstream output_ranted_cars("rented_cars.txt", ios::app);
	ifstream input_ranted_cars("rented_cars.txt");
	while (getline(input_ranted_cars, st))
	{
		no_of_rented_cars++;
	}
	ofstream output_ranted_cars_detail("rented_cars_detail.txt", ios::app);
	ifstream input_ranted_cars_detail("rented_cars_detail.txt");
	while (getline(input_ranted_cars_detail, st))
	{
		rentes_car_details++;
	}
	no_of_cus = no_of_cus / 4;
	no_of_cars = no_of_cars / 6;
	no_of_rented_cars = no_of_rented_cars / 7;
	rentes_car_details = rentes_car_details / 5;

    login();
	return 0;
}

//Login function for Admin and customers
void login()
{
	cout << "                                        **********************************" << endl;
	cout << "                                        **     CAR RENTAL MANAGEMENT    **" << endl;
	cout << "                                        **********************************" << endl;
	char choice;
a:
	cout << "\t Press 1 for Admin login," << endl;
	cout << "\t Press 2 for customer login," << endl;
	cout << "\t Press 3 for exit:" << endl;
	cout << "\t Choice: ";
	cin >> choice;
	cout << endl;
	if (choice != '1' && choice != '2' && choice != '3')
	{
		cout << "\t Invalid, Just press 1, 2 or 3" << endl;
		goto a;
	}

	if (choice == '1')
	{
		//Admin login
		string ID, pass;
	c:
		cout << endl;
		cout << "\t Enter user ID : ";
		cin >> ID;
	b:
		cout << "\t Enter Password: ";
		cin >> pass;
		if (ID == admin_id && pass == admin_pass)
		{
			admin_menu();
		}
		else
		{
			if (ID != admin_id)
			{
				cout << "\t Invalid Admin ID!" << endl;
				goto c;
			}
			if (pass != admin_pass)
			{
				cout << "\t Invalid Password try again" << endl;
				goto b;
			}
			if (ID != admin_id && pass != admin_pass)
			{
				cout << "\t Invalid Admin ID and Password, Try again" << endl;
				goto c;
			}
		}
	}
	if (choice == '2')
	{
		//Customer login
		string ID, pass;
		int customer_number = 0;
	e:
		cout << endl;
		cout << "\t Enter user ID : ";
		cin.ignore();
		getline(cin, ID);
		cout << "\t Enter Password: ";
		cin >> pass;
		ifstream input_cus("customer.txt");
		customer_data* data = new customer_data[no_of_cus];
		for (int i = 0; i < no_of_cus; i++)
		{
			getline(input_cus, data[i].name);
			getline(input_cus, data[i].pass);
			getline(input_cus, data[i].phone);
			getline(input_cus, data[i].address);
		}
		for (int i = 0; i < no_of_cus; i++)
		{
			if (ID == data[i].name && pass == data[i].pass)
			{
				customer_number = i;
			}
		}
		if (ID == data[customer_number].name && pass == data[customer_number].pass)
		{
			customer_menu();
			input_cus.close();
		}
		else
		{
				cout << "\t Invalid User name or Password, Try again" << endl;
				goto e;
		}

	}
	if (choice == '3')
	{
		cout << "\t Thanks for using our service." << endl;
		cout << "\t Have a great day!" << endl;
	}
	
}

//For rent a car to customer
void rent_a_car()
{
	system("cls");
	cout << "                                        **********************************" << endl;
	cout << "                                        *            RENT A CARS         *" << endl;
	cout << "                                        **********************************" << endl;
	cout << endl << endl;
	ifstream input_cars("cars.txt");
	cars* car_data = new cars[no_of_cars];
	string st;
	for (int i = 0; i < no_of_cars; i++)
	{
		getline(input_cars, car_data[i].name);
		getline(input_cars, car_data[i].model);
		getline(input_cars, car_data[i].color);
		getline(input_cars, car_data[i].top_speed);
		getline(input_cars, car_data[i].fuel_avg);
		getline(input_cars, st);
		car_data[i].price_rentPerDay = stoi(st);
	}

	cout << "\t\t**AVAILABLE CARS**" << endl << endl;
	for (int i = 0; i < no_of_cars; i++)
	{
		cout << "\t\t\t**(" << i + 1 << ")**" << endl;
		cout << "\t\tCAR:\t\t" << car_data[i].name << endl;
		cout << "\t\tMODEL:\t\t" << car_data[i].model << endl;
		cout << "\t\tCOLOR:\t\t" << car_data[i].color << endl;
		cout << "\t\tTOP SPEED:\t" << car_data[i].top_speed << " KM/H" << endl;
		cout << "\t\tFUEL AVERAGE:\t" << car_data[i].fuel_avg << " KM/L" << endl;
		cout << "\t\tPRICE:\t\t " << car_data[i].price_rentPerDay << " $" << endl << endl;
		cout << "\t----------------------------------------------------" << endl;
	}
	string choice;
	cout << endl << "Enter the name of car you want to rent: ";
	a:
	cin.ignore();
	getline(cin, choice);
	int car_num = -1;
	for (int i = 0; i < no_of_cars; i++)
	{
		if (choice == car_data[i].name)
		{
			car_num = i;
		}
	}
	cout << endl;
	if (car_num != -1)
	{
		cout << "\t\tCAR         :" << car_data[car_num].name << endl;
		cout << "\t\tMODEL       :" << car_data[car_num].model << endl;
		cout << "\t\tCOLOR       :" << car_data[car_num].color << endl;
		cout << "\t\tTOP SPEED   :" << car_data[car_num].top_speed << " KM/H" << endl;
		cout << "\t\tFUEL AVERAGE:" << car_data[car_num].fuel_avg << " KM/L" << endl;
		cout << "\t\tPRICE       :" << car_data[car_num].price_rentPerDay << " $" << endl << endl;
		char choice1;
		cout << "\tPress 'Y' to rent this vehicle : ";
	c:
		cin >> choice1;
		if (choice1 == 'y' || choice1 == 'Y')
		{
			no_of_rented_cars++;
			rentes_car_details++;
			rented_detail detail;
			ofstream output_detail("rented_cars_detail.txt", ios::app);
			cout << "\tEnter your user_name: ";
			cin.ignore();
			getline(cin, detail.cus_name);
			cout << "\tEnter the Number of days for rent: ";
			cin >> detail.rent_days;
			cout << "\tEnter today's date: ";
			cin.ignore();
			getline(cin, detail.date);
			detail.car_name = car_data[car_num].name;
			detail.bill = car_data[car_num].price_rentPerDay * detail.rent_days;
			cout << "\t\tUser_name    : " << detail.cus_name << endl;
			cout << "\t\tCar name     : " << detail.car_name << endl;
			cout << "\t\tValidity     : " << detail.rent_days << " days" << endl;
			cout << "\t\tAmount to pay: " << detail.bill <<" $" << endl;
			cout << "\t\tDate         : " << detail.date << endl;

			output_detail << detail.cus_name << endl;
			output_detail << detail.car_name << endl;
			output_detail << detail.rent_days << endl;
			output_detail << detail.bill << endl;
			output_detail << detail.date << endl;
			output_detail.close();

			rented_car rent_car;
			rent_car.cname = detail.cus_name;
			rent_car.name = car_data[car_num].name;
			rent_car.model = car_data[car_num].model;
			rent_car.color = car_data[car_num].color;
			rent_car.top_speed = car_data[car_num].top_speed;
			rent_car.fuel_avg = car_data[car_num].fuel_avg;
			rent_car.price_rentPerDay = car_data[car_num].price_rentPerDay;

			ofstream output_rent_cars("rented_cars.txt", ios::app);
			output_rent_cars << rent_car.cname << endl;
			output_rent_cars << rent_car.name << endl;
			output_rent_cars << rent_car.model << endl;
			output_rent_cars << rent_car.color << endl;
			output_rent_cars << rent_car.top_speed << endl;
			output_rent_cars << rent_car.fuel_avg << endl;
			output_rent_cars << rent_car.price_rentPerDay << endl;

			ofstream output_cars("cars.txt");
			swap(car_data[car_num], car_data[no_of_cars - 1]);
			no_of_cars--;
			for (int i = 0; i < no_of_cars; i++)
			{
				output_cars << car_data[i].name << endl;
				output_cars << car_data[i].model << endl;
				output_cars << car_data[i].color << endl;
				output_cars << car_data[i].top_speed << endl;
				output_cars << car_data[i].fuel_avg << endl;
				output_cars << car_data[i].price_rentPerDay << endl;
			}
			output_cars.close();
			input_cars.close();
			output_rent_cars.close();
			output_detail.close();

			cout << "\t\tCAR RENTED SUCCESSFULLY" << endl << endl;
			cout << "\t\t" << system("pause");
			customer_menu();
		}
		else
		{
			cout << "\tJust press 'Y' to rent this vehicle, you don't have another option: ";
			goto c;
		}
	}
	else
	{
		cout << "Entered car name not found try again: ";
		goto a;
	}
}

//For return the car of customer
void return_a_car()
{
	system("cls");
	cout << "                                        **********************************" << endl;
	cout << "                                        *           RETURN A CAR         *" << endl;
	cout << "                                        **********************************" << endl;
	cout << endl << endl;
	cout << "\tEnter your username :";
	string cus_name, car_name, st;
	int counter = 0, counter1 = 0, num = 0;
	cin.ignore();
	getline(cin, cus_name);
	ifstream input_rented_car("rented_cars.txt");
	rented_car* data = new rented_car[no_of_rented_cars];
	for (int i = 0; i < no_of_rented_cars; i++)
	{
		getline(input_rented_car, data[i].cname);
		getline(input_rented_car, data[i].name);
		getline(input_rented_car, data[i].model);
		getline(input_rented_car, data[i].color);
		getline(input_rented_car, data[i].top_speed);
		getline(input_rented_car, data[i].fuel_avg);
		getline(input_rented_car, st);
		data[i].price_rentPerDay = stoi(st);
	}
	for (int i = 0; i < no_of_rented_cars; i++)
	{
		if (cus_name == data[i].cname)
		{
			counter++;
		}
	}
	if (counter > 0)
	{
		cout << "\tYou have rented " << counter << " car" << endl << endl;
		cout << "\t\tDETAILS" << endl;
		for (int i = 0; i < no_of_rented_cars; i++)
		{
			if (cus_name == data[i].cname)
			{
				cout << "\t\tName         : " << data[i].name << endl;
				cout << "\t\tModel        : " << data[i].model << endl;
				cout << "\t\tColor        : " << data[i].color << endl;
				cout << "\t\tTop speed    : " << data[i].top_speed << endl;
				cout << "\t\tFuel average : " << data[i].fuel_avg << endl;
				cout << "\t\tRent price   : " << data[i].price_rentPerDay << endl;
				cout << "\t\t-------------------------------------------------------" << endl;
			}
		}
		cout << "\tEnter the car name you want to return: ";
		d:
		getline(cin, car_name);
		ofstream output_cars("cars.txt", ios::app);
		for (int i = 0; i < no_of_rented_cars; i++)
		{
			if (cus_name == data[i].cname && car_name == data[i].name)
			{
				num = i;
				output_cars << data[i].name << endl;
				output_cars << data[i].model << endl;
				output_cars << data[i].color << endl;
				output_cars << data[i].top_speed << endl;
				output_cars << data[i].fuel_avg << endl;
				output_cars << data[i].price_rentPerDay << endl;
				counter1++;
			}
		}
		if (counter1 == 0)
		{
			cout << "\tEntered car name is not rented by you try another: ";
			goto d;
		}
		if (counter > 0)
		{
			no_of_rented_cars--;
			ofstream rented_cars("rented_cars.txt");
			swap(data[num], data[no_of_rented_cars]);
			for (int i = 0; i < no_of_rented_cars; i++)
			{
				rented_cars << data[i].cname << endl;
				rented_cars << data[i].name << endl;
				rented_cars << data[i].model << endl;
				rented_cars << data[i].color << endl;
				rented_cars << data[i].top_speed << endl;
				rented_cars << data[i].fuel_avg << endl;
				rented_cars << data[i].price_rentPerDay << endl;
			}
			cout << "\t\t RENTED CAR RETURNED SUCCESSFULLY" << endl;
		}
	}
	else
	{
		cout << "\t\tYou have rented NO car!" << endl;
	}
	cout << "\t\t" << system("pause");
	customer_menu();
}

//view available cars
void available_cars()
{
	system("cls");
	cout << "                                        **********************************" << endl;
	cout << "                                        *          AVAILABLE CARS        *" << endl;
	cout << "                                        **********************************" << endl;
	cout << endl << endl;

	string st;
	ifstream input_cars("cars.txt");
	cars* car_data = new cars[no_of_cars];
	for (int i = 0; i < no_of_cars; i++)
	{
		getline(input_cars, car_data[i].name);
		getline(input_cars, car_data[i].model);
		getline(input_cars, car_data[i].color);
		getline(input_cars, car_data[i].top_speed);
		getline(input_cars, car_data[i].fuel_avg);
		getline(input_cars, st);
		car_data[i].price_rentPerDay = stoi(st);
	}

	cout << "\t\tAvailable Cars" << endl << endl;
		for (int i = 0; i < no_of_cars; i++)
		{
			cout << "\t\t\t**(" << i + 1 << ")**" << endl;
			cout << "\t\tCAR:\t\t" << car_data[i].name << endl;
			cout << "\t\tMODEL:\t\t" << car_data[i].model << endl;
			cout << "\t\tCOLOR:\t\t" << car_data[i].color << endl;
			cout << "\t\tTOP SPEED:\t" << car_data[i].top_speed << " KM/H" << endl;
			cout << "\t\tFUEL AVERAGE:\t" << car_data[i].fuel_avg << " KM/L" << endl;
			cout << "\t\tPRICE:\t\t " << car_data[i].price_rentPerDay << " $" << endl << endl;
			cout << "\t----------------------------------------------------" << endl;
		}
		system("pause");
		customer_menu();
}

//rental report of customer
void rental_report()
{
	system("CLS");
	cout << "                                        **********************************" << endl;
	cout << "                                        *          RENTAL REPORTS        *" << endl;
	cout << "                                        **********************************" << endl;
	cout << "\tEnter your user name to check your rental history: ";
	string name, st;
	int counter = 0;
	cin.ignore();
	getline(cin, name);
	ifstream details("rented_cars_detail.txt");
	rented_detail* detail = new rented_detail[rentes_car_details];
	for (int i = 0; i < rentes_car_details; i++)
	{
		getline(details, detail[i].cus_name);
		getline(details, detail[i].car_name);
		getline(details, st);
		detail[i].rent_days = stoi(st);
		getline(details, st);
		detail[i].bill = stoi(st);
		getline(details, detail[i].date);
	}
	cout << endl << "\t\tHISTORY" << endl << endl;
	for (int i = 0; i < rentes_car_details; i++)
	{
		if (name == detail[i].cus_name)
		{
			counter++;
			cout << "\t\tCustomer name: " << detail[i].cus_name << endl;
			cout << "\t\tCar name     : " << detail[i].car_name << endl;
			cout << "\t\tRent days    : " << detail[i].rent_days << endl;
			cout << "\t\tTotal bill   : " << detail[i].bill << endl;
			cout << "\t\tDate        : " << detail[i].date << endl;
			cout << "\t\t------------------------------------------" << endl;
		}
	}
	if (counter == 0)
	{
		cout << "\tYou have no History yet!" << endl;
		cout << "\t\t" << system("pause");
		customer_menu();
	}
	else
	{
		cout << "\t These are your rental reports" << endl;
		cout << "\t\t" << system("pause");
		customer_menu();
	}
}

//to logout
void Logout()
{
	system("CLS");
	login();
}

//admin can change customers passwords by using this function
void change_pass()
{
	system("CLS");
	cout << "                                        **********************************" << endl;
	cout << "                                        *     PASSWORD CHANGING PORTAL   *" << endl;
	cout << "                                        **********************************" << endl;
	char choice;
	string pass1, pass2;
	cout << "\t Press 1 to change your own username & password" << endl;
	cout << "\t Press 2 to change your customers password" << endl;
j:
	cout << "\tChoice: ";
	cin >> choice;
	if (choice == '1')
	{
		cout << "\t Your current username is: " << admin_id << endl;
		cout << "\t Your current password is: " << admin_pass << endl;
		char choice1;
		cout << "\t Press 1 to change your username" << endl;
		cout << "\t Press 2 to change your password" << endl;
		cout << "choice: ";
		x:
		cin >> choice1;
		if (choice1 == '1')
		{
			cout << "Enter a new username:";
			cin.ignore();
			getline(cin, admin_id);
			cout << "\t Username Successfully changed" << endl;
			system("pause");
			admin_menu();

		}
		if (choice1 == '2')
		{
			cout << "\t Enter new password: ";
			cin >> pass1;
			cout << "\t Enter password again: ";
		i:
			cin >> pass2;
			if (pass1 == pass2)
			{
				admin_pass = pass1;
				cout << "\t Password Successfully changed" << endl;
				system("pause");
				admin_menu();
			}
			else
			{
				cout << "\t Enter 2nd password again: ";
				goto i;
			}
		}
		if (choice1 != '1' && choice1 != '2')
		{
			cout << "Enter a valid choice: ";
			goto x;
		}
	}
	if (choice == '2')
	{
		string customer_id, new_pass1, new_pass2;
		int temp_id = -1;
		cout << endl;
		cout << "\t Enter the customer user name whom password you want to change: ";
	h:
		cin.ignore();
		getline(cin, customer_id);
		ifstream input_cus("customer.txt");
		customer_data* data = new customer_data[no_of_cus];
		for (int i = 0; i < no_of_cus; i++)
		{
			getline(input_cus, data[i].name);
			getline(input_cus, data[i].pass);
			getline(input_cus, data[i].phone);
			getline(input_cus, data[i].address);
		}
		for (int i = 0; i < no_of_cus; i++)
		{
			if (customer_id == data[i].name)
			{
				temp_id = i;
			}
		}
		if (temp_id < 0)
		{
			cout << "\t Entered user name not found try another user name: ";
			goto h;
		}
		else
		{
			cout << "\t The current password of user name: " << data[temp_id].name << " is: " << data[temp_id].pass << endl;
			cout << "\t Enter a new password for this user name: ";
			cin >> new_pass1;
		k:
			cout << "\t Enter password again: ";
			cin >> new_pass2;
			if (new_pass1 == new_pass2)
			{
				data[temp_id].pass = new_pass1;
				ofstream output_cus("customer.txt");
				for (int i = 0; i < no_of_cus; i++)
				{
					output_cus << data[i].name << endl;
					output_cus << data[i].pass << endl;
					output_cus << data[i].phone << endl;
					output_cus << data[i].address << endl;
				}
				input_cus.close();
				output_cus.close();
			}
			else
			{
				cout << "\t 2nd one is not same as first enter previous password again" << endl;
				goto k;
			}
		}
	}

	if (choice != '1' && choice != '2')
	{
		cout << "\t Enter a valid option just 1 or 2: ";
		goto j;
	}
}

//admin can view current registered cars by using this function
void view_current_avlbl_car()
{
	system("CLS");
	cout << "                                        *************************************" << endl;
	cout << "                                        * VIEW AVAILABLE CUSMOMERS AND CARS *" << endl;
	cout << "                                        *************************************" << endl << endl;
	cout << "\tPress 1 to view available Customers" << endl;
	cout << "\tPress 2 to view available Cars" << endl;
	char choice;
	cout << "\tChoice: ";
	a:
	cin >> choice;
	if (choice == '1')
	{
		ifstream input_cus("customer.txt");
		customer_data* data = new customer_data[no_of_cus];
		for (int i = 0; i < no_of_cus; i++)
		{
			getline(input_cus, data[i].name);
			getline(input_cus, data[i].pass);
			getline(input_cus, data[i].phone);
			getline(input_cus, data[i].address);
		}
		cout << "\t\tAvailable Customers" << endl << endl;
		for (int i = 0; i < no_of_cus; i++)
		{
			cout << "\t\t\t**(" << i + 1 << ")**" << endl;
			cout << "\t\tNAME:\t\t" << data[i].name << endl;
			cout << "\t\tPASSWORD:\t" << data[i].pass << endl;
			cout << "\t\tPHONE NO.:\t" << data[i].phone << endl;
			cout << "\t\tADDRESS:\t" << data[i].address << endl;
			cout << "\t----------------------------------------------------" << endl;
		}
		cout << endl << system("pause");
		input_cus.close();
		admin_menu();
	}
	if (choice == '2')
	{
		string st;
		ifstream input_cars("cars.txt");
		cars* car_data = new cars[no_of_cars];
		for (int i = 0; i < no_of_cars; i++)
		{
			getline(input_cars, car_data[i].name);
			getline(input_cars, car_data[i].model);
			getline(input_cars, car_data[i].color);
			getline(input_cars, car_data[i].top_speed);
			getline(input_cars, car_data[i].fuel_avg);
			getline(input_cars, st);
			car_data[i].price_rentPerDay = stoi(st);
		}

		cout << "\t\tAvailable Cars" << endl << endl;
		for (int i = 0; i < no_of_cars; i++)
		{
			cout << "\t\t\t**(" << i + 1 << ")**" << endl;
			cout << "\t\tCAR:\t\t" << car_data[i].name << endl;
			cout << "\t\tMODEL:\t\t" << car_data[i].model << endl;
			cout << "\t\tCOLOR:\t\t" << car_data[i].color << endl;
			cout << "\t\tTOP SPEED:\t" << car_data[i].top_speed << " KM/H" << endl;
			cout << "\t\tFUEL AVERAGE:\t" << car_data[i].fuel_avg << " KM/L" << endl;
			cout << "\t\tPRICE:\t\t " << car_data[i].price_rentPerDay << " $" << endl << endl;
			cout << "\t----------------------------------------------------" << endl;
		}
		system("pause");
		input_cars.close();
		admin_menu();
	}
	if (choice != '1' && choice != '2')
	{
		cout << "\tEnter a valid choice: ";
		goto a;
	}
}

//admin can update customer data by using this function
void update_customer_data()
{
	system("CLS");
	cout << "                                        **********************************" << endl;
	cout << "                                        *      UPDATE CUSTOMER DATA      *" << endl;
	cout << "                                        **********************************" << endl;
	cout << endl;
	string choice1, new_name, new_address, new_phone;
	int cus_num = -1;
	char choice2;
	cout << "\t Type the user name of the customer whose data you wanna change: ";
a:
	cin.ignore();
	getline(cin, choice1);
	ifstream input_cus("customer.txt");
	customer_data* data = new customer_data[no_of_cus];
	for (int i = 0; i < no_of_cus; i++)
	{
		getline(input_cus, data[i].name);
		getline(input_cus, data[i].pass);
		getline(input_cus, data[i].phone);
		getline(input_cus, data[i].address);
	}
	for (int i = 0; i < no_of_cus; i++)
	{
		if (choice1 == data[i].name)
		{
			cus_num = i;
		}
	}
	if (cus_num == -1)
	{
		cout << "\t Entered customer name is not register...Try another: ";
		goto a;
	}
	else
	{
		cout << "\t The current details of the customer are: " << endl;
		cout << "\t Name: " << data[cus_num].name << endl;
		cout << "\t Password: " << data[cus_num].pass << endl;
		cout << "\t Phone number: " << data[cus_num].phone << endl;
		cout << "\t Current Address: " << data[cus_num].address << endl << endl;
		cout << "\t Press 1 to modify customer's Name" << endl;
		cout << "\t Press 2 to modify customer's Phone number" << endl;
		cout << "\t Press 3 to modify customer's Address" << endl;
		cout << "\t To modify customer's Password goto the menu and select choice '1'" << endl;
		cout << "Choice: ";
	b:
		cin >> choice2;
		switch (choice2)
		{
		case '1':
			cout << "\t Enter the new username for the customer: ";
			cin.ignore();
			getline(cin, new_name);
			data[cus_num].name = new_name;
			break;
		case '2':
			cout << "\t Enter the new phone number for the customer: ";
			cin >> new_phone;
			cin.ignore();
			data[cus_num].phone = new_phone;
			break;
		case '3':
			cout << "\t Enter the new Address for the customer: ";
			cin.ignore();
			getline(cin, new_address);
			data[cus_num].address = new_address;
			break;
		default:
			cout << "\t Press a valid choice: ";
			goto b;
		}
		ofstream output_cus("customer.txt");
		for (int i = 0; i < no_of_cus; i++)
		{
			output_cus << data[i].name << endl;
			output_cus << data[i].pass << endl;
			output_cus << data[i].phone << endl;
			output_cus << data[i].address << endl;
		}
		input_cus.close();
		output_cus.close();
		cout << "\t Changes have been SAVED" << endl;
		system("pause");
		admin_menu();
	}
}

//admin can add or remove customers by using this function
void add_or_remove_cus()
{
	system("CLS");
	cout << "                                        **********************************" << endl;
	cout << "                                        *     ADD OR REMOVE A CUSTOMER   *" << endl;
	cout << "                                        **********************************" << endl;
	char choice;
	cout << "\tPress 1 to Add a customer" << endl;
	cout << "\tPress 2 to Remove a customer" << endl;
	cout << "\tChoice: ";
	a:
	cin >> choice;
	if (choice == '1')
	{
		no_of_cus++;
		ofstream output_cus("customer.txt",ios::app);
		customer_data data;
		cout << "\tEnter the name of new customer: ";
		cin.ignore();
		getline(cin, data.name);
		cout << "\tEnter the password for new customer: ";
		getline(cin, data.pass);
		cout << "\tEnter the phone number of new customer: ";
		getline(cin, data.phone);
		cout << "\tEnter the address of new customer: ";
		getline(cin, data.address);

		output_cus << data.name << endl;
		output_cus << data.pass << endl;
		output_cus << data.phone << endl;
		output_cus << data.address << endl;
		output_cus.close();
		cout << endl << "\t\t NEW CUSTOMER REGISTERED SUCCESSFULLY" << endl;
		system("pause");
		admin_menu();

	}
	if (choice == '2')
	{
		string cus;
		int cus_num = -1;
		ifstream input_cus("customer.txt");
		customer_data* data = new customer_data[no_of_cus];
		for (int i = 0; i < no_of_cus; i++)
		{
			getline(input_cus, data[i].name);
			getline(input_cus, data[i].pass);
			getline(input_cus, data[i].phone);
			getline(input_cus, data[i].address);
		}
		cout << "\tEnter the username of customer whom who want to remove: ";
		z:
		cin.ignore();
		getline(cin, cus);
		for (int i = 0; i < no_of_cus; i++)
		{
			if (data[i].name == cus)
			{
				cus_num = i;
			}
		}
		if (cus_num != -1)
		{
			char y;
			cout << "\t\tCustomer found" << endl << endl;
			cout << "\tName    : " << data[cus_num].name << endl;
			cout << "\tPassword: " << data[cus_num].pass << endl;
			cout << "\tPhone   : " << data[cus_num].phone << endl;
			cout << "\tAddress : " << data[cus_num].address << endl << endl;
			cout << "\tPress 'Y' to remove the customer: ";
			y:  
			cin >> y;
			if (y == 'y' || y == 'Y')
			{
				swap(data[cus_num], data[no_of_cus - 1]);
				no_of_cus--;
				ofstream output_cus("customer.txt");
				customer_data* data1 = new customer_data[no_of_cus];
				for (int i = 0; i < no_of_cus; i++)
				{
					data1[i].name = data[i].name;
					data1[i].pass = data[i].pass;
					data1[i].phone = data[i].phone;
					data1[i].address = data[i].address;
				}
				for (int i = 0; i < no_of_cus; i++)
				{
					output_cus << data1[i].name << endl;
					output_cus << data1[i].pass << endl;
					output_cus << data1[i].phone << endl;
					output_cus << data1[i].address << endl;
				}
				input_cus.close();
				output_cus.close();
				cout << "\tSELECTED CUSTOMER REMOVED" << endl << endl;
				cout << "\t" << system("pause");
				admin_menu();
			}
			else
			{
				cout << "\tJust press 'Y' to remove you don't have any other option as you selected a customer: ";
				goto y;
			}
		}
		else
		{
			cout << "\tEntered user name not found try another one";
			goto z;
		}
	}
	if (choice != '1' && choice != '2')
	{
		cout << "\tEnter a valid choice: ";
		goto a;
	}

}

//admin can add or remove cars by using this function
void add_or_remove_car()
{
	system("CLS");
	cout << "                                        **********************************" << endl;
	cout << "                                        *        ADD OR REMOVE A CAR     *" << endl;
	cout << "                                        **********************************" << endl;
	char choice;
	cout << "\tPress 1 to Add a new car" << endl;
	cout << "\tPress 2 to Remove an existing car" << endl;
	cout << "\tChoice: ";
	a:
	cin >> choice;
	if (choice == '1')
	{
		no_of_cars++;
		cars new_car;
		ofstream output_cars("cars.txt", ios::app);
		cin.ignore();
		cout << "\tEnter the name of the new car: ";
		getline(cin, new_car.name);
		cout << "\tEnter the model of the car: ";
		cin >> new_car.model;
		cout << "\tEnter the color of the car: ";
		cin.ignore();
		getline(cin, new_car.color);
		cout << "\tEnter the top speed of the car: ";
		cin >> new_car.top_speed;
		cout << "\tEnter the fuel average of the car: ";
		cin >> new_car.fuel_avg;
		cout << "\tEnter the rent price per day of the car: ";
		cin >> new_car.price_rentPerDay;

		output_cars << new_car.name << endl;
		output_cars << new_car.model << endl;
		output_cars << new_car.color << endl;
		output_cars << new_car.top_speed << endl;
		output_cars << new_car.fuel_avg << endl;
		output_cars << new_car.price_rentPerDay << endl;
		output_cars.close();
		cout << endl << "\t\t NEW CAR ADDED SUCCESSFULLY" << endl;
		system("pause");
		admin_menu();
	}
	if (choice == '2')
	{
		string st, name;
		int car_num = -1;
		ifstream input_cars("cars.txt");
		cars* car_data = new cars[no_of_cars];
		for (int i = 0; i < no_of_cars; i++)
		{
			getline(input_cars, car_data[i].name);
			getline(input_cars, car_data[i].model);
			getline(input_cars, car_data[i].color);
			getline(input_cars, car_data[i].top_speed);
			getline(input_cars, car_data[i].fuel_avg);
			getline(input_cars, st);
			car_data[i].price_rentPerDay = stoi(st);
		}
		cout << "\tEnter the car name, you want to remove: ";
	b:
		cin.ignore();
		getline(cin, name);
		for (int i = 0; i < no_of_cars; i++)
		{
			if (name == car_data[i].name)
			{
				car_num = i;
			}
		}
			if (car_num != -1)
			{
				cout << "\t\tCar found" << endl << endl;
				cout << "\tName        : " << car_data[car_num].name << endl;
				cout << "\tModel       : " << car_data[car_num].model << endl;
				cout << "\tColor       : " << car_data[car_num].color << endl;
				cout << "\tTop speed   : " << car_data[car_num].top_speed << endl;
				cout << "\tFuel Average: " << car_data[car_num].fuel_avg << endl;
				cout << "\tRent Price  : " << car_data[car_num].price_rentPerDay << endl << endl;

				char choice1;
				cout << "\tPress 'Y' to remove this vehicle : ";
				c:
				cin >> choice1;
				if (choice1 == 'y' || choice1 == 'Y')
				{
					swap(car_data[car_num], car_data[no_of_cars - 1]);
					no_of_cars--;
					ofstream output_cars("cars.txt");
					cars* car_data1 = new cars[no_of_cars];
					for (int i = 0; i < no_of_cars; i++)
					{
						car_data1[i].name = car_data[i].name;
						car_data1[i].model = car_data[i].model;
						car_data1[i].color = car_data[i].color;
						car_data1[i].top_speed = car_data[i].top_speed;
						car_data1[i].fuel_avg = car_data[i].fuel_avg;
						car_data1[i].price_rentPerDay = car_data[i].price_rentPerDay;
					}

					for (int i = 0; i < no_of_cars; i++)
					{
						output_cars << car_data1[i].name << endl;
						output_cars << car_data1[i].model << endl;
						output_cars << car_data1[i].color << endl;
						output_cars << car_data1[i].top_speed << endl;
						output_cars << car_data1[i].fuel_avg << endl;
						output_cars << car_data1[i].price_rentPerDay << endl;
					}
					output_cars.close();
					cout << "\t\tSELECTED CAR REMOVED SUCCESSFULLY" << endl;
					cout << "\t\t" << system("pause");
					admin_menu();
				}
				else
				{
					cout << "\tJust enter 'Y' to continue the process you have not any other option: ";
					goto c;
				}

			}
			else
			{
				cout << "\tEntered car not found, try another name: ";
				goto b;
			}
	}
	if (choice != '1' && choice != '2')
	{
		cout << "Enter a valid choice: ";
		goto a;
	}
}

void all_reports()
{
	system("CLS");
	cout << "                                        **********************************" << endl;
	cout << "                                        *            ALL REPORTS         *" << endl;
	cout << "                                        **********************************" << endl << endl;
	string st;
	ifstream details("rented_cars_detail.txt");
	rented_detail* detail = new rented_detail[rentes_car_details];
	for (int i = 0; i < rentes_car_details; i++)
	{
		getline(details, detail[i].cus_name);
		getline(details, detail[i].car_name);
		getline(details, st);
		detail[i].rent_days = stoi(st);
		getline(details, st);
		detail[i].bill = stoi(st);
		getline(details, detail[i].date);
	}
	cout << "\t\t* RENT REPORTS *" << endl;
	for (int i = 0; i < rentes_car_details; i++)
	{
		cout << "\t\tCustomer Name: " << detail[i].cus_name << endl;
		cout << "\t\tCar Name     : " << detail[i].car_name << endl;
		cout << "\t\tDays for rent: " << detail[i].rent_days << endl;
		cout << "\t\tTotal bill   : " << detail[i].bill << endl;
		cout << "\t\tDate         : " << detail[i].date << endl;
		cout << "\t\t------------------------------------------" << endl;
	}
	cout << endl;
	cout << "\t\t* CARS REPORT *" << endl;
	cout << "\tThere are still " << no_of_cars << " cars available for rent." << endl;
	cout << "\tThere are " << no_of_rented_cars << " cars rented" << endl;
	cout << "\tTotal " << rentes_car_details << " rents and transaction are made successfully" << endl << endl;
	cout << "\t\t* CUSTOMERS REPORT *" << endl;
	cout << "\tThere are still " << no_of_cus << " number of customers registered" << endl;
	system("pause");
	admin_menu();
}

void admin_menu()
{
	system("CLS");
	cout << "                                        **********************************" << endl;
	cout << "                                        *            ADMIN MENU          *" << endl;
	cout << "                                        **********************************" << endl;
	cout << endl << "Welcome sir, good to see you again" << endl;
	cout << "What you want to do?" << endl << endl;
	cout << "\t 1.Change password." << endl;
	cout << "\t 2.View current available cars and customer." << endl;
	cout << "\t 3.Update customer data." << endl;
	cout << "\t 4.Add or remove a customer." << endl;
	cout << "\t 5.Add or remove a car." << endl;
	cout << "\t 6.Check reports related to customer and car." << endl;
	cout << "\t 7.Update car data." << endl;
	cout << "\t 8.Logout." << endl;
	char choice;
g:
	cout << "choice: ";
	cin >> choice;
	switch (choice)
	{
	case '1':
		change_pass();
		break;
	case '2':
		view_current_avlbl_car();
		break;
	case '3':
		update_customer_data();
		break;
	case '4':
		add_or_remove_cus();
		break;
	case '5':
		add_or_remove_car();
		break;
	case '6':
		all_reports();
		break;
	case '7':
		update_car();
		break;
	case '8':
		Logout();
		break;
	default:
	{
		cout << "Enter a valid choice: " << endl;
		goto g;
	}
	}
}

void customer_menu()
{
	system("CLS");
	cout << "                                        **********************************" << endl;
	cout << "                                        *          CUSTOMER MENU         *" << endl;
	cout << "                                        **********************************" << endl;
	cout << endl << "Welcome sir, what you want to do?" << endl;
	cout << "\t 1.Wanna rent a car." << endl;
	cout << "\t 2.Want to return a car." << endl;
	cout << "\t 3.View available cars." << endl;
	cout << "\t 4.Want to generate rental reports for your own rents." << endl;
	cout << "\t 5.Logout." << endl;
	char choice;
f:
	cout << "choice: ";
	cin >> choice;
	switch (choice)
	{
	case '1':
		rent_a_car();
		break;
	case '2':
		return_a_car();
		break;
	case '3':
		available_cars();
		break;
	case '4':
		rental_report();
		break;
	case '5':
		Logout();
		break;
	default:
	{
		cout << "Enter a valid choice: " << endl;
		goto f;
	}
	}
}

void update_car()
{
	system("cls");
	cout << "                                        **********************************" << endl;
	cout << "                                        *          UPDATE CAR DATA       *" << endl;
	cout << "                                        **********************************" << endl << endl;
	cars* data = new cars[no_of_cars];
	ifstream car_data("cars.txt");
	string st, car;
	char choice;
	int num = -1;
	for (int i = 0; i < no_of_cars; i++)
	{
		getline(car_data, data[i].name);
		getline(car_data, data[i].model);
		getline(car_data, data[i].color);
		getline(car_data, data[i].top_speed);
		getline(car_data, data[i].fuel_avg);
		getline(car_data, st);
		data[i].price_rentPerDay = stoi(st);
	}
	for (int i = 0; i < no_of_cars; i++)
	{
		cout << "\t\t\t**(" << i + 1 << ")**" << endl;
		cout << "\t\tCAR:\t\t" << data[i].name << endl;
		cout << "\t\tMODEL:\t\t" << data[i].model << endl;
		cout << "\t\tCOLOR:\t\t" << data[i].color << endl;
		cout << "\t\tTOP SPEED:\t" << data[i].top_speed << " KM/H" << endl;
		cout << "\t\tFUEL AVERAGE:\t" << data[i].fuel_avg << " KM/L" << endl;
		cout << "\t\tPRICE:\t\t " << data[i].price_rentPerDay << " $" << endl << endl;
		cout << "\t----------------------------------------------------" << endl;
	}
	cout << "\tEnter the name of the car whose data you want to change: ";
	a:
	cin.ignore();
	getline(cin, car);
	for (int i = 0; i < no_of_cars; i++)
	{
		if (car == data[i].name)
		{
			num = i;
		}
	}
	if (num == -1)
	{
		cout << "\tEntered car not found try again:";
		goto a;
	}
	else
	{
		cout << "\t\tCAR:\t\t" << data[num].name << endl;
		cout << "\t\tMODEL:\t\t" << data[num].model << endl;
		cout << "\t\tCOLOR:\t\t" << data[num].color << endl;
		cout << "\t\tTOP SPEED:\t" << data[num].top_speed << " KM/H" << endl;
		cout << "\t\tFUEL AVERAGE:\t" << data[num].fuel_avg << " KM/L" << endl;
		cout << "\t\tPRICE:\t\t " << data[num].price_rentPerDay << " $" << endl << endl;
		cout << "\tPress 1 to change the name of car" << endl;
		cout << "\tPress 2 to change the name of model" << endl;
		cout << "\tPress 3 to change the name of color" << endl;
		cout << "\tPress 4 to change the name of top speed" << endl;
		cout << "\tPress 5 to change the name of fuel average" << endl;
		cout << "\tPress 6 to change the name of price" << endl;
		b:
		cin >> choice;
		switch (choice)
		{
		case '1':
			cout << "\tEnter a new name for the car: ";
			cin.ignore();
			getline(cin, data[num].name);
			break;
		case '2':
			cout << "\tEnter a new model for the car: ";
			cin.ignore();
			getline(cin, data[num].model);
			break;
		case '3':
			cout << "\tEnter a new color for the car: ";
			cin.ignore();
			getline(cin, data[num].color);
			break;
		case '4':
			cout << "\tEnter a new top speed for the car: ";
			cin.ignore();
			getline(cin, data[num].top_speed);
			break;
		case '5':
			cout << "\tEnter a new fuel average for the car: ";
			cin.ignore();
			getline(cin, data[num].fuel_avg);
			break;
		case '6':
			cout << "\tEnter a new rent price for the car: ";
			cin >> data[num].price_rentPerDay;
			break;
		default:
			cout << "Enter a valid choice";
			goto b;
		}

		ofstream write("cars.txt");
		for (int i = 0; i < no_of_cars; i++)
		{
			write << data[i].name << endl;
			write << data[i].model << endl;
			write << data[i].color << endl;
			write << data[i].top_speed << endl;
			write << data[i].fuel_avg << endl;
			write << data[i].price_rentPerDay << endl;
		}
		cout << "\t\tCHANGES ARE SAVED SUCCESSFULLY" << endl;
		system("pause");
		admin_menu();
	}
}