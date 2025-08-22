#include<iostream>
#include<vector>
using namespace std;
//E2019@#678
class Account {			//    __________________________ Class Account __________________________
	private:
	    int id;
	    string name;
	    string password;
	    double balance = 0;
	    bool active = true;
	
	public:
		Account(){

		}
		
		Account(int id,string password){
			this->id = id;
	        this->password = password;

		}
		Account(int id,string name,string password){
			this->id = id;
	        this->password = password;
	        this->name = name;

		}
	    // Setter for id
	    void setId(int id) {
	        this->id = id;
	    }
	
	    // Getter for id
	    int getId() {
	        return id;
	    }
	    
	    // Setter for id
	    void setPassword(string password) {
	        this->password = password;
	    }
	
	    // Getter for id
	    string getPassword() {
	        return password;
	    }
	
	    // Setter for name
	    void setName(string name) {
	        this->name = name;
	    }
	
	    // Getter for name
	    string getName() {
	        return name;
	    }
	
	    // Setter for balance
	    void setBalance(double balance) {
	        this->balance = balance;
	    }
	
	    // Getter for balance
	    double getBalance() {
	        return balance;
	    }
	
	    // Setter for active
	    void setActive(bool active) {
	        this->active = active;
	    }
	
	    // Getter for active
	    bool isActive() {
	        return active;
	    }
};





class Walet {						//    __________________________ Class Walet __________________________


	private:
		string name = "Eraa Soft Cash";
		double totalBlance;
		vector<Account> accounts;

	public:

		bool setAccount(Account acc){          //  ______ Funcation setAccount ______
			for (int i=0;i<accounts.size();i++){ 
				if (acc.getId() == accounts[i].getId()) {
					return false;
				}
			}
			accounts.push_back(acc);
			return true;
		}
		
		Account getAccount(Account acc){		  //  ______ Funcation getAccount ______
			for (int i=0;i<accounts.size();i++){ 
				if (acc.getId() == accounts[i].getId() &&
				 acc.getPassword() == accounts[i].getPassword()) {
					return accounts[i];
				}
			}
			Account ac;
			ac.setId(-1);
			return ac;
		}

		
		bool updateBalance(Account acc) {		 //  ______ Funcation updateBalance ______
			for (int i=0;i<accounts.size();i++){ 
				if (acc.getId() == accounts[i].getId()) {
					accounts[i].setBalance(acc.getBalance());
					return true;
				}
			}
			
			return false;
		}
		

		bool convertToAccount(Account searchedAccount,int id, int money) { //  ______ Funcation convertToAccount ______
			int r1 = 0;
			int r2 = 0; 
			for (int i=0;i<accounts.size();i++){ 
				if (searchedAccount.getId() == accounts[i].getId()) {
					accounts[i].setBalance(searchedAccount.getBalance());
					r1 = 1;	
				}
			}

			
			for (int i=0;i<accounts.size();i++){ 
				if (id == accounts[i].getId()) {
					accounts[i].setBalance(accounts[i].getBalance() + money);
					r2 = 1;	
				}
			}
			
			return (r1 && r2);

		}


		bool updatactive(Account acc)  //  ______ Funcation updatactive ______
		{						
			for (int i=0;i<accounts.size();i++)
			{ 
					if (acc.getId() == accounts[i].getId())
					{
						accounts[i].setActive(acc.isActive());
						return true;
					}
					break;
			}
					return false;
		}


		

		bool searshactive(int id)  //  ______ Funcation updatactive ______
		{						
			for (int i=0;i<accounts.size();i++)
			{ 
					if (id == accounts[i].getId())
					{
						return accounts[i].isActive();
					}
					break;
			}
					return false;
		}


		

};

class WaletService {  				//    __________________________ Class WaletService __________________________

	private:
		Walet walet;

	public:

		bool addAccount(Account acc)
		{		//  ______ Funcation addAccount ______
			 return walet.setAccount(acc);
		}
		
		Account searchAccount(Account acc)  //  ______ Funcation searchAccount ______
		{	
			 return walet.getAccount(acc);
		}

		bool updateBalance(Account acc) //  ______ Funcation updateBalance ______
		{   
			return walet.updateBalance(acc);
		}

		bool convertToAccount(Account searchedAccount,int id, int money) //  ______ Funcation convertToAccount ______
		{
			return walet.convertToAccount(searchedAccount, id, money);	
		}

		bool updatactive(Account acc) 			//  ______ Funcation updatactive ______
		{
			return walet.updatactive(acc);
		}

		bool searshactive(int id)	//  ______ Funcation searshactive ______
		{
			return walet.searshactive(id);
		}

};

class ValidationService {			//    __________________________ Class ValidationService __________________________
	
	
	public:
		bool isValidName(string name){ 		//  ______ Funcation isValidName ______
			if (name.size() < 5) {
				cout<<" ___________*** name size must be greater than 5 ***___________"<<endl;
				return false;
			}
			
			if (!(name[0] >= 65 &&  name[0] <= 90)) {
				cout<<"___________*** first char name must be upper case ***___________"<<endl;
				return false;
			}
			
			return true;
		}

		bool isValidPassword(string password)   //  ______ Funcation isValidPassword ______
		{
			int x = 0 ,y = 0 , z = 0;
			for(int i=0; i<password.size() ;i++)
			{
				if(password[i] >= 65 && password[i] <= 90 )
				{
					x++;
				}
				else if(password[i] >= 97 && password[i] <= 122)
				{
					y++;
				}
				else if(password[i] >= 48 && password[i] <= 57)
				{
					z++;
				}
			}


			if(x > 0 && y > 0 && z > 0) { return 1;}
			else{ cout << "***___ Must Your Password contain upre case and lower case and num ___***\n"; return 0;}
		}
		
};




class AccountService 		//    __________________________ Class AccountService __________________________
 {
	private:
		WaletService waletService;
		ValidationService validationService;
		double money;

	public:
		Account createAccount()	//  ______ Funcation createAccount ______
		{
			cout<<"___________ Please Enter your id: ";
			int id;
			cin>>id;

			cout<<"\n___________ Please Enter your name: ";
			string name;
			cin>>name;

			cout<<"\n___________ Please Enter your password: ";
			string password;
			cin>>password; cout << endl;

			
			if(validationService.isValidName(name) && validationService.isValidPassword(password) )
			{
				Account acc(id, name, password);
			
				bool cteated = waletService.addAccount(acc);
				
				if (cteated) 
				{
					cout<<" ___________*** Success Create Account with id : "<<id<<endl;
				} 
				else {  cout<<"___________*** OPS not created because your id is existed id: "<<id<<endl;  }

				return acc;
			}
			
			Account acc;
			return acc;
		}
		
		bool updateBalance(Account acc)	//  ______ Funcation updateBalance ______
		{
			return waletService.updateBalance(acc);
		}

		bool updatactive(Account acc)	//  ______ Funcation updatactive ______
		{
			return waletService.updatactive(acc);
		}

		bool searshactive(int id)	//  ______ Funcation searshactive ______
		{
			return waletService.searshactive(id);
		}

		
		bool convertToAccount(Account searchedAccount,int id, int money) //  ______ Funcation convertToAccount ______
		{
			return waletService.convertToAccount(searchedAccount, id, money);
		}
		
		
	Account login()			//  ______ Funcation login ______
	{
					int res = 3 ;
					bool ch = 0;
					Account searchedAccount2;
					
					cout<<"________________ Please Enter your id: ";
					int id;
					cin>>id;

			while(res)
			{
							cout<<"\n________________ Please Enter your password: ";
							string password;
							cin >>password;

							Account acc(id,password);
							searchedAccount2 = waletService.searchAccount(acc);


					if (searshactive(id) != 1)
					{		
							cout << searshactive(id) << endl;
							cout << "\n___________##### Your account is been susbended #####___________" << endl;
							Account acc;
							return acc;
					}

					if(searchedAccount2.getId() == id)
					{
							break;
					}

					if(res > 1) 
					{
							cout << "___________*** Erorr in passwoard ***___________\n";
					}
					else{
							ch = true;
							searchedAccount2.setId(id);
							searchedAccount2.setActive(false);
							updatactive(searchedAccount2);

						}
							res--;
			}

					if(updatactive(searchedAccount2) && ch)
					{
							cout << "___________##### Your account has been susbended #####___________" << endl;
							cout << endl;
							Account acc;
							return acc;
					}


		if (searchedAccount2.getId() != -1) 
		{	
			cout<<"___________ Login Success :)"<<endl;
			cout<<"___________ id = "<<searchedAccount2.getId()<<endl;
			cout<<"___________ name = "<<searchedAccount2.getName()<<endl;
			cout<<"___________ Balance = "<<searchedAccount2.getBalance()<<endl;

			while(true)
			{
				cout<<"choose service you need"<<endl;
				cout<<" __________ 1.Deposit     2.WithDraw   3.Convert to Account  4.Exit __________"<<endl;
				int res;
				cin>>res;
				if(res == 4)
				break;
				
				switch(res)
				{
					case 1:
					cout<<"___________ Enter money you want to add ______________"<<endl;
					cin>>money;
					searchedAccount2.setBalance(searchedAccount2.getBalance() + money);
								
					if (updateBalance(searchedAccount2))
					{
					  cout<<"___________ Success Deposit"<<endl;
					} else {cout<<"___________ UnSuccess Deposit"<<endl;}
					  break;

					case 2:
					cout<<"___________ Enter money you want to get"<<endl;
					cin>>money;
							

					if (searchedAccount2.getBalance() >= money) 
					{
							searchedAccount2.setBalance(searchedAccount2.getBalance() - money);
						if (updateBalance(searchedAccount2))
						{
								cout<<"___________ Success WithDraw"<<endl;
						} 
						else { cout<<"___________ UnSuccess WithDraw"<<endl;}

					} 
					else { cout<<"___________ your balance now is "<<searchedAccount2.getBalance()<<" and you need "<<money<<endl;}
						break;


					case 3:
							cout<<"___________ Enter money you want to convert ___________"<<endl;
							cin>>money;
							if (searchedAccount2.getBalance() >= money) 
							{
								searchedAccount2.setBalance(searchedAccount2.getBalance() - money);
								cout<<"___________ Enter id of account you want to convert ___________"<<endl;
								int id;
								cin>>id;
										

								if (convertToAccount(searchedAccount2, id, money))
								{
									cout<<"___________ Success convert"<<endl;
								} 
								else  { cout<<"___________ UnSuccess convert"<<endl; }

					    	}     
							else { cout<<"your balance now is "<<searchedAccount2.getBalance()<<" and you need to convert "<<money<<endl;}
							break;


					default: {cout<<"Invalid input"<<endl;}
				}
				
			} 
				
		}  else { cout<<"Login failed :("<<endl;  }
				  return searchedAccount2;
		
			
	}
		
};


class ApplicationService 		//    __________________________ Class ApplicationService __________________________
{
	
	private: 
		AccountService accountService;

	public:
		void startWalet()  //  ______ Funcation startWalet ______
		{		  
			
			while(true)
			{
					cout<<"___________***** Hello in Eraa Soft Cash. *****___________"<<endl;
					cout<<"___________ please enter what you need to do?!___________"<<endl;
					cout<<"___________ 1.createAccount      2.login       3.Exit ___________"<<endl;
					int res;
					cin>>res;
					
					if (res == 1) 
					{
						Account acc = accountService.createAccount();
					} 
					
					else if (res == 2) 
					{ 
						Account acc = accountService.login();
					}
					
					else if (res == 3)
					{
						cout<<"___________ Thanks for you."<<endl;
						break;
					} else {  cout<<"___________Invalid input."<<endl; }
			}
		}
	
};


int main(){					//    __________________________ int main __________________________

	ApplicationService applicationService;
	applicationService.startWalet();
	
}