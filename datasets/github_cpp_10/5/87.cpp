




#include <iostream>
using std::cout;
using std::endl;


template <int To, int TowerNum>
struct Tower {
	static const bool t = To == TowerNum ? 1 : 0;
};


template <int Size, int From, int To , int Spare>
struct HanoiHilton {
	
	static const unsigned long long moves = 1 +
			HanoiHilton<Size-1, From, Spare, To>::moves +
			HanoiHilton<Size-1, Spare, To, From>::moves;
			
	
	enum {
		m_to_1 = Tower<To, 1>::t + HanoiHilton<Size-1, From, Spare, To>::m_to_1 + 
								  HanoiHilton<Size-1, Spare, To, From>::m_to_1,
		m_to_2 = Tower<To, 2>::t + HanoiHilton<Size-1, From, Spare, To>::m_to_2 +
									HanoiHilton<Size-1, Spare, To, From>::m_to_2,
		m_to_3 = Tower<To, 3>::t + HanoiHilton<Size-1, From, Spare, To>::m_to_3 +
									HanoiHilton<Size-1, Spare, To, From>::m_to_3
	};
};


template <int From, int To, int Spare>
struct HanoiHilton<1, From, To, Spare> {
	static const unsigned long long moves = 1;
	enum {
		m_to_1 = Tower<To, 1>::t,
		m_to_2 = Tower<To, 2>::t,
		m_to_3 = Tower<To, 3>::t};
};


template <int Size>
struct Hanoi {
	static const unsigned long long moves = HanoiHilton<Size, 1, 2, 3>::moves;
	enum {
		m_to_1 = HanoiHilton<Size, 1, 2, 3>::m_to_1,
		m_to_2 = HanoiHilton<Size, 1, 2, 3>::m_to_2,
		m_to_3 = HanoiHilton<Size, 1, 2, 3>::m_to_3
	};
};

int main()
{
	Hanoi<5> h;		
	
	cout << "Total Moves: " << h.moves << endl;
	cout << "\n\tTo Tower 1: " << h.m_to_1 << "\n\tTo Tower 2: "
		<< h.m_to_2 << "\n\tTo Tower 3: " << h.m_to_3 << endl;
	
}

