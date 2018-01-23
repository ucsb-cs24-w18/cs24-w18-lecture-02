//dieGame.cpp
//Diba Mirza
// Simple game of die using OOP
// Frequency AC

#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;


class Player{
	public:
		void setName(string );
		string getName() const;
		void rollDie();
		void displayDie() const; //accessor
		int getScore() const; //accessor 

	private:
		string name_;	
		int dieOne_;
		int dieTwo_;
		int score_;
};

void Player::setName(string name){
	name_ = name;
}

string Player::getName() const{
	return name_;
}

void Player::rollDie(){
	dieOne_ = rand()%6 + 1;
	dieTwo_ = rand()%6 + 1;
	if ( dieOne_ == dieTwo_){
		score_= 4*dieOne_;
	}else{
		score_= dieOne_ + dieTwo_;
	}

}

void Player::displayDie() const{
	cout<<name_<<"'s die values are: ";
	cout<<"("<< dieOne_<<", "<<dieTwo_<<")\n";
}

int Player::getScore() const{
	return score_;
}


int main(){
	Player p1, p2;
	p1.setName("Diba");
	p2.setName("Adib");
	string winner;
	char play;
	srand(time(0));

	do{
		p1.rollDie();
		p2.rollDie();
		p1.displayDie();
		p2.displayDie();

		if(p1.getScore() == p2.getScore()){
			cout<<"It's a Tie!"<<endl;
		}else{
			winner = p1.getScore()> p2.getScore()? p1.getName():p2.getName();
			cout<<winner<<" wins!!!"<<endl;
		}
		cout<<"Play again? (y/n) : ";
		cin>>play;

	}while(play == 'y');

  
  return 0;
}
