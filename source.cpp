/*
주니어 디자인 프로젝트
2015.10.13~
the Online Shopping Mall Simulator
김가림2014112068
윤재문2014112037
*/
#include "header.h"
string itos(int num)
{
	//int->string
	ostringstream oss;
	oss << num;
	return oss.str();
}
void setColor(string color)
{
	// 윤재문(15.11.29) - 글씨색을 조정가능하게 하는 함수
	if (color == "red")
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	else if (color == "blue")
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
void gotoxy(int x, int y)   //function that set position of console window
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void showStartingScreen()
{
	/*************************************************************************
	- 김가림 (15.11.26)
	- Function   : showStartingScreen
	- Input      : None
	- Output     : None
	- Proceduere : 프로그램 시작시 실행
	- 수정 날짜  :
	*************************************************************************/
	cout << "┌─────────────────────────────────────┐" << endl;
	cout << "│ THE                                                                      │" << endl;
	cout << "│   ■■■   ■  ■   ■■■   ■■■   ■■■  ■■■   ■■■   ■■■   │" << endl;
	cout << "│   ■       ■  ■   ■  ■   ■  ■   ■  ■    ■     ■  ■   ■       │" << endl;
	cout << "│   ■■■   ■■■   ■  ■   ■■■   ■■■    ■     ■  ■   ■       │" << endl;
	cout << "│       ■   ■  ■   ■  ■   ■       ■        ■     ■  ■   ■  ■   │" << endl;
	cout << "│   ■■■   ■  ■   ■■■   ■       ■      ■■■   ■  ■   ■■■   │" << endl;
	cout << "│                                                                          │" << endl;
	cout << "│   ■      ■    ■■    ■        ■            ■        ■             │" << endl;
	cout << "│   ■■  ■■  ■    ■  ■        ■          ■  ■■■■ ■            │" << endl;
	cout << "│   ■  ■  ■  ■■■■  ■        ■       ■■   ■■■■   ■■        │" << endl;
	cout << "│   ■      ■  ■    ■  ■        ■              ■■■■               │" << endl;
	cout << "│   ■      ■  ■    ■  ■■■■  ■■■■        ■■■■    SIMULATOR  │" << endl;
	cout << "│                                                                          │" << endl;
	cout << "└─────────────────────────────────────┘" << endl;
	cout << "                         PRESS ANY KEY TO START" << endl;
}
void saveData()
{
	/*************************************************************************
	- 윤재문(15.11.26)
	- Function   : saveData
	- Input      : None
	- Output     : None
	- Proceduere :벡터를 파일에 다시저장
	- 수정 날짜  : 윤재문(15.11.28)
	- productCount추가
	윤재문(15.11.30)
	-order 부분 추가
	*************************************************************************/
	ofstream out1("user.txt");
	for (int i = 0; i<vec_user.size(); i++)
	{
		string s;
		s = vec_user.at(i).id + " " + vec_user.at(i).password + " " + vec_user.at(i).name + " " + vec_user.at(i).phone + " " + itos(vec_user.at(i).coin) + " " + itos(vec_user.at(i).productCount) + " " + itos(vec_user.at(i).feat1_cuty) + " " + itos(vec_user.at(i).feat2_sexy) + " " + itos(vec_user.at(i).feat3_formal) + " " + itos(vec_user.at(i).feat4_casual) + " " + vec_user.at(i).address;
		if (i == vec_user.size() - 1)
			out1 << s;
		else
			out1 << s << endl;
	}
	out1.close();
	ofstream out2("product.txt");
	for (int i = 0; i<vec_product.size(); i++)
	{
		string s;
		s = vec_product.at(i).name + " " + itos(vec_product.at(i).stock) + " " + itos(vec_product.at(i).cost) + " " + vec_product.at(i).size + " " + itos(vec_product.at(i).sellNumber);
		s += " " + itos(vec_product.at(i).feat1_cuty) + " " + itos(vec_product.at(i).feat2_sexy) + " " + itos(vec_product.at(i).feat3_formal) + " " + itos(vec_product.at(i).feat4_casual);
		if (i == vec_product.size() - 1)
			out2 << s;
		else
			out2 << s << endl;
	}
	out2.close();
	ofstream out3("order.txt");
	for (int i = 0; i<vec_order.size(); i++)
	{
		string s;
		s = vec_order.at(i).userName + " " + vec_order.at(i).userPhone + " " + vec_order.at(i).userAddress + " " + vec_order.at(i).productName + " " + vec_order.at(i).productSize + " " + itos(vec_order.at(i).productNum) + " " + itos(vec_order.at(i).totalPrice) + " " + itos(vec_order.at(i).isDelivered);
		if (i == vec_order.size() - 1)
			out3 << s;
		else
			out3 << s << endl;
	}
	out3.close();
	Sleep(150);
}
Start::Start()
{
	/*************************************************************************
	- 윤재문(15.11.14)
	- Function   : Start()
	- Input      : None
	- Output     : None
	- Proceduere : Start구조체의 기본생성자
	- 수정 날짜  : 윤재문(15.11.22)
	- productInfo 텍스트 벡터에 저장하는부분 추가
	- login() 리턴타입 void->int , menu()->menu(int )수정
	윤재문(15.11.28)
	-productCount추가
	윤재문(15.11.30)
	-order 불러오는 부분 추가
	윤재문(15.12.05)
	-키보드 조작가능하도록 수정
	-로그아웃 가능하도록 변경
	*************************************************************************/
	ifstream in1("user.txt");
	while (!in1.eof()){
		string s;
		getline(in1, s);
		struct UserInfo temp;
		temp.id = s.substr(0, s.find(" "));
		s = s.substr(s.find(" ") + 1);
		temp.password = s.substr(0, s.find(" "));
		s = s.substr(s.find(" ") + 1);
		temp.name = s.substr(0, s.find(" "));
		s = s.substr(s.find(" ") + 1);
		temp.phone = s.substr(0, s.find(" "));
		s = s.substr(s.find(" ") + 1);
		temp.coin = stoi(s.substr(0, s.find(" ")));
		s = s.substr(s.find(" ") + 1);
		temp.productCount = stoi(s.substr(0, s.find(" ")));
		s = s.substr(s.find(" ") + 1);
		temp.feat1_cuty = stoi(s.substr(0, s.find(" ")));
		s = s.substr(s.find(" ") + 1);
		temp.feat2_sexy = stoi(s.substr(0, s.find(" ")));
		s = s.substr(s.find(" ") + 1);
		temp.feat3_formal = stoi(s.substr(0, s.find(" ")));
		s = s.substr(s.find(" ") + 1);
		temp.feat4_casual = stoi(s.substr(0, s.find(" ")));
		s = s.substr(s.find(" ") + 1);
		temp.address = s;
		vec_user.push_back(temp);
	}
	in1.close();

	ifstream in2("product.txt");
	while (!in2.eof()){
		string s;
		getline(in2, s);
		struct ProductInfo temp;
		temp.name = s.substr(0, s.find(" "));
		s = s.substr(s.find(" ") + 1);
		temp.stock = stoi(s.substr(0, s.find(" ")));
		s = s.substr(s.find(" ") + 1);
		temp.cost = stoi(s.substr(0, s.find(" ")));
		s = s.substr(s.find(" ") + 1);
		temp.size = s.substr(0, s.find(" "));
		s = s.substr(s.find(" ") + 1);
		temp.sellNumber = stoi(s.substr(0, s.find(" ")));
		s = s.substr(s.find(" ") + 1);
		temp.feat1_cuty = stoi(s.substr(0, s.find(" ")));
		s = s.substr(s.find(" ") + 1);
		temp.feat2_sexy = stoi(s.substr(0, s.find(" ")));
		s = s.substr(s.find(" ") + 1);
		temp.feat3_formal = stoi(s.substr(0, s.find(" ")));
		s = s.substr(s.find(" ") + 1);
		temp.feat4_casual = stoi(s);
		vec_product.push_back(temp);
	}
	in2.close();

	ifstream in3("order.txt");
	while (!in3.eof()){
		string s;
		getline(in3, s);
		struct Order temp;
		temp.userName = s.substr(0, s.find(" "));
		s = s.substr(s.find(" ") + 1);
		temp.userPhone = s.substr(0, s.find(" "));
		s = s.substr(s.find(" ") + 1);
		temp.userAddress = s.substr(0, s.find(" "));
		s = s.substr(s.find(" ") + 1);
		temp.productName = s.substr(0, s.find(" "));
		s = s.substr(s.find(" ") + 1);
		temp.productSize = s.substr(0, s.find(" "));
		s = s.substr(s.find(" ") + 1);
		temp.productNum = stoi(s.substr(0, s.find(" ")));
		s = s.substr(s.find(" ") + 1);
		temp.totalPrice = stoi(s.substr(0, s.find(" ")));
		s = s.substr(s.find(" ") + 1);
		temp.isDelivered = stoi(s);
		vec_order.push_back(temp);
	}
	in3.close();
	int point = 0;
	while (1)
	{
		setColor("white");
		gotoxy(30, 8);
		char key;
		if (point == 0)
		{
			setColor("red");
			cout << "로그인  <<" << endl;
			setColor("white");
			gotoxy(30, 10);
			cout << "회원가입   " << endl;
		}
		else if (point == 1)
		{
			setColor("white");
			cout << "로그인       " << endl;
			setColor("red");
			gotoxy(30, 10);
			cout << "회원가입<<" << endl;
			setColor("white");
		}
		key = getch();
		if (key == 72 && point != 0)
		{
			point--;
		}
		else if (key == 80&&point!=1)
		{
			point++;
		}
		else if (key == 32)
		{
			if (point == 0)
			{
				system("cls");
				int userIndex;
				userIndex = login();
				menu(userIndex);
			}
			else if (point == 1)
			{
				system("cls");
				signUp();
			}
		}
	}
	//saveData();
}
int Start::login()
{
	/*************************************************************************
	- 김가림(15.11.15)
	- Function   : login()
	- Input      : None
	- Output     : None
	- Proceduere : 벡터의 처음부터 끝까지
	- 수정 날짜  : 윤재문(15.11.22) - 리턴타입 void-> int로 변경하여 userIndex를 반환하도록 수정
	김가림(15.11.28) - 아이디가 admin일 때 관리자 로그인
	*************************************************************************/

	string tempID;
	string tempPW;
	int userIndex;
	cout << "********** 로 그 인 **********" << endl;
	cout << "아이디를 입력해주세요 : ";
	cin >> tempID;
	if (tempID == "admin") //관리자 아이디
	{
		cout << "비밀번호를 입력해주세요 : ";
		cin >> tempPW;
		if (tempPW == "1234")
			//관리자 비밀번호
			isAdmin = true;
		return -1;
	}
	else{
		while ((userIndex = isUserID(tempID)) == -1)
		{
			cout << "아이디가 정확하지 않습니다. 다시 입력해주세요 : ";
			cin >> tempID;
		}
		cout << "비밀번호를 입력해주세요 : ";
		cin >> tempPW;
		while (vec_user[userIndex].password != tempPW)
		{
			cout << "비밀번호가 정확하지 않습니다. 다시 입력해주세요 : ";
			cin >> tempPW;
		}
		cout << "***로그인 성공***" << endl;
		Sleep(1500);
		isAdmin = false;
		return userIndex;
	}
}
void Start::signUp()
{
	/*************************************************************************
	- 김가림(15.11.15)
	- Function   : signUp()
	- Input      : None
	- Output     : None
	- Proceduere : 새로운 회원의 정보를 받아와서 vector에 저장
	- 수정 날짜  : (15.12.01) 중복된 아이디 수정
	*************************************************************************/

	UserInfo newUser;
	string tempID;
	cout << "********** 회 원 가 입 **********" << endl;
	cout << "아이디를 입력하세요 : ";
	cin >> tempID;
	while (tempID == "admin")
	{
		cout << "이 아이디는 사용하실 수 없습니다." << endl;
		cout << "아이디를 입력하세요 : ";
		cin >> tempID;
	}
	while (isUserID(tempID) != -1)	//아이디가 있을때 다시 입력받는다
	{
		cout << "중복된 아이디입니다. 새로운 아이디를 입력하세요 : ";
		cin >> tempID;
	}
	newUser.id = tempID;
	cout << "비밀번호를 입력하세요 : ";
	cin >> newUser.password;

	cout << "이름을 입력하세요 : ";
	cin >> newUser.name;

	cout << "전화번호를 입력하세요 : ";
	cin >> newUser.phone;

	cout << "주소를 입력하세요 : ";
	cin >> newUser.address;

	signUpQuestion(newUser.feat1_cuty, newUser.feat2_sexy, newUser.feat3_formal, newUser.feat4_casual);


	cout << "cuty : " << newUser.feat1_cuty << endl;
	cout << "sexy:" << newUser.feat2_sexy << endl;
	cout << "formal : " << newUser.feat3_formal << endl;
	cout << "casual: " << newUser.feat4_casual << endl;


	cout << "**회원가입 축하 코인 10만원을 적립해드립니다**" << endl;
	newUser.coin = 100000;			//회원가입시 coin 10만원 적립
	newUser.productCount = 0;		//productCount를 0으로 초기화
	vec_user.push_back(newUser);	//새로운 user를 벡터에 저장
}
void Start::menu(int userIndex)
{
	/*************************************************************************
	- 윤재문,김가림(15.11.15)
	- Function   : menu()
	- Input      : int userIndex
	- Output     : None
	- Proceduere : 메뉴창을 통해 원하는 기능으로 진입
	- 수정 날짜  :   윤재문(15.11.22) - searchProduct(),menuProduct()구현
	김가림(15.12.05) - 장바구니 기능 구현
	윤재문(15.12.05) - 로그아웃 기능 구현, switch->키보드 조작하도록 수정
	*************************************************************************/
	
	int inputKey;
	bool logOut = false;
	int point = 0;
	system("cls");
	while (!isAdmin&&logOut==false)//관리자가 아닐 때
	{
		gotoxy(1, 1);
		currentUser = User(userIndex);
		char key;
		if (point == 0)
		{
			cout << "********** 메 뉴 **********" << endl;
			cout << "1. 상품 검색    <<" << endl;
			cout << "2. 상품 목록      " << endl;
			cout << "3. 내정보 확인    " << endl;
			cout << "4. 코인 충전      " << endl;
			cout << "5. 장바구니       " << endl;
			cout << "6. 로그아웃       " << endl;
		}
		else if (point == 1)
		{
			cout << "********** 메 뉴 **********" << endl;
			cout << "1. 상품 검색      " << endl;
			cout << "2. 상품 목록    <<" << endl;
			cout << "3. 내정보 확인    " << endl;
			cout << "4. 코인 충전      " << endl;
			cout << "5. 장바구니       " << endl;
			cout << "6. 로그아웃       " << endl;
		}
		else if (point == 2)
		{
			cout << "********** 메 뉴 **********" << endl;
			cout << "1. 상품 검색      " << endl;
			cout << "2. 상품 목록      " << endl;
			cout << "3. 내정보 확인  <<" << endl;
			cout << "4. 코인 충전      " << endl;
			cout << "5. 장바구니       " << endl;
			cout << "6. 로그아웃       " << endl;
		}
		else if (point == 3)
		{
			cout << "********** 메 뉴 **********" << endl;
			cout << "1. 상품 검색      " << endl;
			cout << "2. 상품 목록      " << endl;
			cout << "3. 내정보 확인    " << endl;
			cout << "4. 코인 충전    <<" << endl;
			cout << "5. 장바구니       " << endl;
			cout << "6. 로그아웃       " << endl;
		}
		else if (point == 4)
		{
			cout << "********** 메 뉴 **********" << endl;
			cout << "1. 상품 검색      " << endl;
			cout << "2. 상품 목록      " << endl;
			cout << "3. 내정보 확인    " << endl;
			cout << "4. 코인 충전      " << endl;
			cout << "5. 장바구니     <<" << endl;
			cout << "6. 로그아웃       " << endl;
		}
		else if (point == 5)
		{
			cout << "********** 메 뉴 **********" << endl;
			cout << "1. 상품 검색      " << endl;
			cout << "2. 상품 목록      " << endl;
			cout << "3. 내정보 확인    " << endl;
			cout << "4. 코인 충전      " << endl;
			cout << "5. 장바구니       " << endl;
			cout << "6. 로그아웃     <<" << endl;
		}
		key = getch();
		if (key == 72 && point != 0)
			point--;
		else if (key == 80 && point != 5)
		{
			point++;
		}
		else if (key == 32)
		{
			system("cls");
			if (point == 0)
			{
				currentUser.searchProduct();
			}
			else if (point == 1)
			{
				currentUser.menuProduct();
			}
			else if (point == 2)
			{
				currentUser.myInfo();
			}
			else if (point == 3)
			{
				currentUser.coinCharge();
			}
			else if (point == 4)
			{
				currentUser.showShoppingCart();
			}
			else if (point == 5)
			{
				logOut = currentUser.logOut();
			}
		}
	}

	while (isAdmin&&logOut==false)
	{
		system("cls");
		gotoxy(1, 1);
		char key;
		if (point == 0)
		{
			cout << "********** 메 뉴 **********" << endl;
			cout << "1. 주문서확인   <<" << endl;
			cout << "2. 상품 목록      " << endl;
			cout << "3. 상품 검색      " << endl;
			cout << "4. 상품 추가      " << endl;
			cout << "5. 로그 아웃      " << endl;
		}
		else if (point == 1)
		{
			cout << "********** 메 뉴 **********" << endl;
			cout << "1. 주문서확인     " << endl;
			cout << "2. 상품 목록    <<" << endl;
			cout << "3. 상품 검색      " << endl;
			cout << "4. 상품 추가      " << endl;
			cout << "5. 로그 아웃      " << endl;
		}
		else if (point == 2)
		{
			cout << "********** 메 뉴 **********" << endl;
			cout << "1. 주문서확인     " << endl;
			cout << "2. 상품 목록      " << endl;
			cout << "3. 상품 검색    <<" << endl;
			cout << "4. 상품 추가      " << endl;
			cout << "5. 로그 아웃      " << endl;
		}
		else if (point == 3)
		{
			cout << "********** 메 뉴 **********" << endl;
			cout << "1. 주문서확인     " << endl;
			cout << "2. 상품 목록      " << endl;
			cout << "3. 상품 검색      " << endl;
			cout << "4. 상품 추가    <<" << endl;
			cout << "5. 로그 아웃      " << endl;
		}
		else if (point == 4)
		{
			cout << "********** 메 뉴 **********" << endl;
			cout << "1. 주문서확인     " << endl;
			cout << "2. 상품 목록      " << endl;
			cout << "3. 상품 검색      " << endl;
			cout << "4. 상품 추가      " << endl;
			cout << "5. 로그 아웃    <<" << endl;
		}
		key = getch();
		if (key == 72 && point != 0)
			point--;
		else if (key == 80 && point != 4)
		{
			point++;
		}
		else if (key == 32)
		{
			system("cls");
			if (point == 0)
			{
				currentAdmin.getOrder();
			}
			else if (point == 1)
			{
				currentAdmin.menuProduct();
			}
			else if (point == 2)
			{
				currentAdmin.searchProduct();
			}
			else if (point == 3)
			{
				currentAdmin.addProduct();
			}
			else if (point == 4)
			{
				logOut = currentAdmin.logOut();
			}
		}
	}
}
int Start::isUserID(string _id)
{
	/*************************************************************************
	- 김가림(15.11.15)
	- Function   : isUserID(string _id)
	- Input      : 확인할 id
	- Output     : 아이디가 없다면 0, 있다면 벡터 내의 인덱스 return
	- Proceduere : 벡터에 회원의 아이디가 존재하는지 확인
	- 수정 날짜  : 아이디가 없을때 0이 아니라 -1을 리턴하도록 수정
	*************************************************************************/

	int flag = -1;
	for (int i = 0; i <vec_user.size(); i++)
	{
		string tempString = vec_user.at(i).id;
		if (_id.compare(tempString) == 0)	//같은 값이면 if문 실행
		{
			flag = i;
		}
	}
	return flag; //없으면 -1 리턴
}
void Start::signUpQuestion(int &sexy, int &cuty, int &formal, int &casual)
{
	/*************************************************************************
	- 김가림(15.11.25)
	- Function   : signUpQuestion()
	- Input      : none
	- Output     : None
	- Proceduere : 설문조사를 통해 회원 정보의 초기값을 받는다.
	- 수정 날짜  : 김가림(15.12.13) 입력받을 때에 예외처리
	*************************************************************************/

	sexy = 0;
	cuty = 0;
	formal = 0;
	casual = 0;
	system("cls");
	char inputChar;
	cin.sync();

	cout << "**회원 정보 초기값 입력을 위한 설문조사**" << endl;
	cout << "맞으면 Y, 보통은 S, 아니면 N를 입력하세요." << endl;
	cout << "1. 나는 밝은 옷을 좋아한다." << endl;
	cin >> inputChar;
	while ((inputChar != 'y') && (inputChar != 'Y') && (inputChar != 's') && (inputChar != 'S') && (inputChar != 'n') && (inputChar != 'N'))
	{
		cout << "올바른 값을 입력해주세요." << endl;
		cin >> inputChar;
	}
	switch (inputChar){
	case('y') :
	case('Y') :
			  cuty += 3;
		casual += 1;
		break;
	case('s') :
	case('S') :
			  cuty += 1;
		break;
	case('n') :
	case('N') :
			  sexy += 3; formal += 1;
		break;
	default:
		break;
	}

	cout << "2. 나는 노출에 대해 거부감이 없다." << endl;
	cin >> inputChar;
	while ((inputChar != 'y') && (inputChar != 'Y') && (inputChar != 's') && (inputChar != 'S') && (inputChar != 'n') && (inputChar != 'N'))
	{
		cout << "올바른 값을 입력해주세요." << endl;
		cin >> inputChar;
	}
	switch (inputChar){
	case('y') :
	case('Y') :
			  sexy += 3;
		break;
	case('s') :
	case('S') :
			  sexy += 1; casual += 1;
		break;
	case('n') :
	case('N') :
			  formal += 5; sexy += 5;
		break;
	default:
		break;
	}

	cout << "3. 나는 캐릭터가 그려진 옷을 좋아한다." << endl;
	cin >> inputChar;
	while ((inputChar != 'y') && (inputChar != 'Y') && (inputChar != 's') && (inputChar != 'S') && (inputChar != 'n') && (inputChar != 'N'))
	{
		cout << "올바른 값을 입력해주세요." << endl;
		cin >> inputChar;
	}
	switch (inputChar){
	case('y') :
	case('Y') :
			  cuty += 5;
		break;
	case('s') :
	case('S') :
			  cuty += 3; casual += 3;
		break;
	case('n') :
	case('N') :
			  formal += 5; sexy += 3;
		break;
	default:
		break;
	}

	cout << "4. 나는 격식을 갖춰서 옷을 입는다." << endl;
	cin >> inputChar;
	while ((inputChar != 'y') && (inputChar != 'Y') && (inputChar != 's') && (inputChar != 'S') && (inputChar != 'n') && (inputChar != 'N'))
	{
		cout << "올바른 값을 입력해주세요." << endl;
		cin >> inputChar;
	}
	switch (inputChar){
	case('y') :
	case('Y') :
			  formal += 5;
		break;
	case('s') :
	case('S') :
			  formal += 3;
		break;
	case('n') :
	case('N') :
			  casual += 5; sexy += 3;
		break;
	default:
		break;
	}

	cout << "5. 나는 피어싱을 했다.(할 생각이 있다)" << endl;
	cin >> inputChar;
	while ((inputChar != 'y') && (inputChar != 'Y') && (inputChar != 's') && (inputChar != 'S') && (inputChar != 'n') && (inputChar != 'N'))
	{
		cout << "올바른 값을 입력해주세요." << endl;
		cin >> inputChar;
	}
	switch (inputChar){
	case('y') :
	case('Y') :
			  sexy += 3; casual += 5;
		break;
	case('s') :
	case('S') :
			  break;
	case('n') :
	case('N') :
			  formal += 5;
		break;
	default:
		break;
	}

	cout << "6. 나는 핑크색을 좋아한다." << endl;
	cin >> inputChar;
	while ((inputChar != 'y') && (inputChar != 'Y') && (inputChar != 's') && (inputChar != 'S') && (inputChar != 'n') && (inputChar != 'N'))
	{
		cout << "올바른 값을 입력해주세요." << endl;
		cin >> inputChar;
	}
	switch (inputChar){
	case('y') :
	case('Y') :
			  cuty += 5;
		break;
	case('s') :
	case('S') :
			  cuty += 3;
		break;
	case('n') :
	case('N') :
			  sexy += 5;
		break;
	default:
		break;
	}

	cout << "7. 나는 스니커즈를 좋아한다." << endl;
	cin >> inputChar;
	while ((inputChar != 'y') && (inputChar != 'Y') && (inputChar != 's') && (inputChar != 'S') && (inputChar != 'n') && (inputChar != 'N'))
	{
		cout << "올바른 값을 입력해주세요." << endl;
		cin >> inputChar;
	}
	switch (inputChar){
	case('y') :
	case('Y') :
			  casual += 5;
		break;
	case('s') :
	case('S') :
			  casual += 3;
		break;
	case('n') :
	case('N') :
			  formal += 5; sexy += 3;
		break;
	default:
		break;
	}

	cout << "8. 나는 스트라이프 티를 좋아한다." << endl;
	cin >> inputChar;
	while ((inputChar != 'y') && (inputChar != 'Y') && (inputChar != 's') && (inputChar != 'S') && (inputChar != 'n') && (inputChar != 'N'))
	{
		cout << "올바른 값을 입력해주세요." << endl;
		cin >> inputChar;
	}
	switch (inputChar){
	case('y') :
	case('Y') :
			  casual += 5; formal += 3;
		break;
	case('s') :
	case('S') :
			  casual += 3;
		break;
	case('n') :
	case('N') :
			  sexy += 5;
		break;
	default:
		break;
	}

	cout << "9. 나는 검정색을 좋아한다." << endl;
	cin >> inputChar;
	while ((inputChar != 'y') && (inputChar != 'Y') && (inputChar != 's') && (inputChar != 'S') && (inputChar != 'n') && (inputChar != 'N'))
	{
		cout << "올바른 값을 입력해주세요." << endl;
		cin >> inputChar;
	}
	switch (inputChar){
	case('y') :
	case('Y') :
			  sexy += 3;
		break;
	case('s') :
	case('S') :
			  sexy += 1;
		break;
	case('n') :
	case('N') :
			  cuty += 5;
		break;
	default:
		break;
	}

	cout << "10. 나는 스냅백을 좋아한다." << endl;
	cin >> inputChar;
	while ((inputChar != 'y') && (inputChar != 'Y') && (inputChar != 's') && (inputChar != 'S') && (inputChar != 'n') && (inputChar != 'N'))
	{
		cout << "올바른 값을 입력해주세요." << endl;
		cin >> inputChar;
	}
	switch (inputChar){
	case('y') :
	case('Y') :
			  casual += 5;
		break;
	case('s') :
	case('S') :
			  casual += 3;
		break;
	case('n') :
	case('N') :
			  sexy += 3; formal += 3;
		break;
	default:
		break;
	}

	cout << "11. 나는 평소에 귀엽다는 말을 들어본 적 있다." << endl;
	cin >> inputChar;
	while ((inputChar != 'y') && (inputChar != 'Y') && (inputChar != 's') && (inputChar != 'S') && (inputChar != 'n') && (inputChar != 'N'))
	{
		cout << "올바른 값을 입력해주세요." << endl;
		cin >> inputChar;
	}
	switch (inputChar){
	case('y') :
	case('Y') :
			  cuty += 7;
		break;
	case('s') :
	case('S') :
			  cuty += 5;
		break;
	case('n') :
	case('N') :
			  sexy += 5; formal += 5;
		break;
	default:
		break;
	}

	cout << "12. 나는 풀세팅하는 것이 귀찮지 않다." << endl;
	cin >> inputChar;
	while ((inputChar != 'y') && (inputChar != 'Y') && (inputChar != 's') && (inputChar != 'S') && (inputChar != 'n') && (inputChar != 'N'))
	{
		cout << "올바른 값을 입력해주세요." << endl;
		cin >> inputChar;
	}
	switch (inputChar){
	case('y') :
	case('Y') :
			  sexy += 5; formal += 5;
		break;
	case('s') :
	case('S') :
			  formal += 3;
		break;
	case('n') :
	case('N') :
			  casual += 5;
		break;
	default:
		break;
	}

	cout << "13. 평소에 향수 뿌리는 것을 좋아한다." << endl;
	cin >> inputChar;
	while ((inputChar != 'y') && (inputChar != 'Y') && (inputChar != 's') && (inputChar != 'S') && (inputChar != 'n') && (inputChar != 'N'))
	{
		cout << "올바른 값을 입력해주세요." << endl;
		cin >> inputChar;
	}
	switch (inputChar){
	case('y') :
	case('Y') :
			  sexy += 3;
		break;
	case('s') :
	case('S') :
			  sexy += 1;
		break;
	case('n') :
	case('N') :
			  casual += 3;
		break;
	default:
		break;
	}

	cout << "14. 나는 타투를 했다.(할 생각이 있다.)" << endl;
	cin >> inputChar;
	while ((inputChar != 'y') && (inputChar != 'Y') && (inputChar != 's') && (inputChar != 'S') && (inputChar != 'n') && (inputChar != 'N'))
	{
		cout << "올바른 값을 입력해주세요." << endl;
		cin >> inputChar;
	}
	switch (inputChar){
	case('y') :
	case('Y') :
			  sexy += 5;
		break;
	case('s') :
	case('S') :
			  sexy += 3; casual += 3;
		break;
	case('n') :
	case('N') :
			  cuty += 5; formal += 3;
		break;
	default:
		break;
	}

	cout << "15. 나는 셔츠를 즐겨 입는다." << endl;
	cin >> inputChar;
	while ((inputChar != 'y') && (inputChar != 'Y') && (inputChar != 's') && (inputChar != 'S') && (inputChar != 'n') && (inputChar != 'N'))
	{
		cout << "올바른 값을 입력해주세요." << endl;
		cin >> inputChar;
	}
	switch (inputChar){
	case('y') :
	case('Y') :
			  formal += 5;
		break;
	case('s') :
	case('S') :
			  formal += 3;
		break;
	case('n') :
	case('N') :
			  casual += 5;
		break;
	default:
		break;
	}

	cout << "16. 나느 패딩보다 코트를 입는다." << endl;
	cin >> inputChar;
	while ((inputChar != 'y') && (inputChar != 'Y') && (inputChar != 's') && (inputChar != 'S') && (inputChar != 'n') && (inputChar != 'N'))
	{
		cout << "올바른 값을 입력해주세요." << endl;
		cin >> inputChar;
	}
	switch (inputChar){
	case('y') :
	case('Y') :
			  formal += 3; sexy += 1;
		break;
	case('s') :
	case('S') :
			  formal += 1;
		break;
	case('n') :
	case('N') :
			  casual += 5;
		break;
	default:
		break;
	}

	cout << "17. 나는 레이스달린 옷을 좋아한다." << endl;
	cin >> inputChar;
	while ((inputChar != 'y') && (inputChar != 'Y') && (inputChar != 's') && (inputChar != 'S') && (inputChar != 'n') && (inputChar != 'N'))
	{
		cout << "올바른 값을 입력해주세요." << endl;
		cin >> inputChar;
	}
	switch (inputChar){
	case('y') :
	case('Y') :
			  cuty += 5;
		break;
	case('s') :
	case('S') :
			  cuty += 3;
		break;
	case('n') :
	case('N') :
			  sexy += 3; casual += 3;
		break;
	default:
		break;
	}

	cout << "18. 나는 멜빵을 즐겨 입는다." << endl;
	cin >> inputChar;
	while ((inputChar != 'y') && (inputChar != 'Y') && (inputChar != 's') && (inputChar != 'S') && (inputChar != 'n') && (inputChar != 'N'))
	{
		cout << "올바른 값을 입력해주세요." << endl;
		cin >> inputChar;
	}
	switch (inputChar){
	case('y') :
	case('Y') :
			  cuty += 5; casual += 3;
		break;
	case('s') :
	case('S') :
			  casual += 1;
		break;
	case('n') :
	case('N') :
			  sexy += 5;
		break;
	default:
		break;
	}

	cout << "19. 나는 청바지를 자주 입는다." << endl;
	cin >> inputChar;
	while ((inputChar != 'y') && (inputChar != 'Y') && (inputChar != 's') && (inputChar != 'S') && (inputChar != 'n') && (inputChar != 'N'))
	{
		cout << "올바른 값을 입력해주세요." << endl;
		cin >> inputChar;
	}
	switch (inputChar){
	case('y') :
	case('Y') :
			  casual += 5;
		break;
	case('s') :
	case('S') :
			  casual += 3;
		break;
	case('n') :
	case('N') :
			  sexy += 5; formal += 5;
		break;
	default:
		break;
	}

	cout << "20. 나는 인상이 강하다." << endl;
	cin >> inputChar;
	while ((inputChar != 'y') && (inputChar != 'Y') && (inputChar != 's') && (inputChar != 'S') && (inputChar != 'n') && (inputChar != 'N'))
	{
		cout << "올바른 값을 입력해주세요." << endl;
		cin >> inputChar;
	}
	switch (inputChar){
	case('y') :
	case('Y') :
			  sexy += 5; formal += 5;
		break;
	case('s') :
	case('S') :
			  sexy += 3;
		break;
	case('n') :
	case('N') :
			  cuty += 5;
		break;
	default:
		break;
	}


	system("cls");
}
User::User(int index)
{
	/*************************************************************************
	- 김가림
	- Function   : User
	- Input      : int index
	- Output     : None
	- Proceduere : User클래스의 생성자
	- 수정 날짜  :
	*************************************************************************/

	userIndex = index;
	id = vec_user.at(index).id;
	password = vec_user.at(index).password;
	name = vec_user.at(index).name;
	phone = vec_user.at(index).phone;
	coin = vec_user.at(index).coin;
	address = vec_user.at(index).address;
	feat1_cuty = vec_user.at(index).feat1_cuty;
	feat2_sexy = vec_user.at(index).feat2_sexy;
	feat3_formal = vec_user.at(index).feat3_formal;
	feat4_casual = vec_user.at(index).feat4_casual;
	productCount = vec_user.at(index).productCount;
}
void User::searchProduct()
{
	/*************************************************************************
	- 윤재문(15.11.22)
	- Function   : searchProduct
	- Input      : vector <ProductInfo> vec
	- Output     : None
	- Proceduere : 상품명으로 검색
	- 수정 날짜  :
	윤재문(15.11.28)
	- 상품명중 일부만 포함해도 검색가능하도록 구현
	윤재문(15.12.06)
	- 키보드로 조작가능하게 수정, 추천상품 처리가능하도록 구현
	*************************************************************************/

	string search;
	vector <int> temp; //검색된 결과를 담는 벡터
	int productIndex = -1;
	int page = 1;	//페이지표시를 위한 변수
	int point = 0;	//상품 선택을 위한 변수
	int check;
	system("cls");
	cout << "상품명을 입력해 주세요 >>";
	cin >> search;
	/*******검색된 결과 저장******/
	for (int i = 0; i < vec_product.size(); i++)
	{
		if (vec_product.at(i).name.find(search) != vec_product.at(i).name.npos)
		{
			temp.push_back(productIndex = i);
		}
	}
	if (temp.size() != 0)	//검색된 상품이 있으면
	{
		while (1)
		{
			/**********검색결과 출력부분**********/
			gotoxy(1, 1);
			char key;
			setColor("blue");
			cout << "back to menu: backspace       select: spacebar\npage control: left,right      product control: up,down \n\n";
			setColor("white");
			cout << "" << search << "" << "에 대한 검색결과:" << "총" << temp.size() << "상품이 검색되었습니다." << endl;
			for (int i = 10 * (page - 1); i < page * 10; i++)
			{
				if (i < temp.size())
				{
					if (i % 10 == point)
					{
						setColor("red");
						cout << temp.at(i) + 1 << "번 상품: " << vec_product.at(temp.at(i)).name << endl;
						check = temp.at(i);
						setColor("white");
					}
					else
						cout << temp.at(i) + 1 << "번 상품: " << vec_product.at(temp.at(i)).name << endl;
				}
			}
			gotoxy(1, 16);
			cout << page << "/" << (temp.size() - 1) / 10 + 1;	//페이지 표시
			/***************키보드조작부분***********/
			key = getch();
			if (key == 8)
			{
				system("cls");
				return;
			}
			else if (key == 75 && page != 1)   //left arrow
			{
				page--;
				point = 0;
				system("cls");
			}
			else if (key == 72 && point != 0)   //down arrow
				point--;
			else if (key == 77 && page != ((temp.size() - 1) / 10) + 1)   //right arrow
			{
				page++;
				point = 0;
				system("cls");
			}
			else if (key == 80 && point != 9)   //up arrrow
			{
				if (page == (temp.size() / 10) + 1 && point == (temp.size() % 10) - 1)   //상품이 10개미만인경우 마지막 상품까지만 가리킴
				{
					//do noting
				}
				else
					point++;
			}
			else if (key == 32)
			{
				Product temp(vec_product.at(check));
				temp.detailInfo(userIndex);
			}
		}
	}
}
void User::menuProduct()
{
	/*************************************************************************
	- 윤재문(15.11.28)
	- Function   : menuProduct
	- Input      :
	- Output     : None
	- Proceduere : 모든 상품들을 나열하여 보여줌
	- 수정 날짜  : 김가림(15.11.28)
	*************************************************************************/
	int page = 1;
	int point = 0;
	int check;
	system("cls");
	while (1)
	{
		/*************목록 출력**************/
		gotoxy(1, 1);
		char key;
		setColor("blue");
		cout << "돌아가기: backspace       자세히보기: spacebar" << endl;
		cout << "이젠페이지: left          다음페이지: right   " << endl;
		cout << "상품선택: up, down        추천상품!!: r         히트상품: h" << endl;
		setColor("white");
		for (int i = 10 * (page - 1); i < page * 10; i++)
		{
			if (i < vec_product.size())
			{
				if (i % 10 == point)
				{
					setColor("red");
					cout << i + 1 << ": 제품명: " << vec_product.at(i).name << endl;
					check = i;
					setColor("white");
				}
				else
					cout << i + 1 << ": 제품명: " << vec_product.at(i).name << endl;
			}
		}
		gotoxy(1, 15);
		cout << page << "/" << (vec_product.size() - 1) / 10 + 1;	//페이지 표시
		/************키보드조작 부분*********/
		key = getch();
		if (key == 8)
		{
			system("cls");
			return;
		}
		else if (key == 75 && page != 1)   //left arrow
		{
			page--;
			point = 0;
			system("cls");
		}
		else if (key == 72 && point != 0)   //down arrow
			point--;
		else if (key == 77 && page != ((vec_product.size() - 1) / 10) + 1)   //right arrow
		{
			page++;
			point = 0;
			system("cls");
		}
		else if (key == 80 && point != 9)   //up arrrow
		{
			if (page == (vec_product.size() / 10) + 1 && point == (vec_product.size() % 10) - 1)   //상품이 10개미만인경우 마지막 상품까지만 가리킴
			{
				//do noting
			}
			else
				point++;
		}
		else if (key == 32)	//spacebar
		{
			Product temp(vec_product.at(check));
			temp.detailInfo(userIndex);
		}
		else if (key == 'r' || key == 'R')
		{
			recommendProduct();
		}
		else if (key == 'h'||key=='H')
		{
			showSellNumber();
		}
		Sleep(30);
	}
}
void User::myInfo()
{
	/*************************************************************************
	- 김가림(15.11.28)
	- Function   : myInfo()
	- Input      : None
	- Output     : None
	- Proceduere : 내 정보 확인 페이지
	- 수정 날짜  :
	*************************************************************************/
	system("cls");
	gotoxy(1, 1);
	cout << "****내 정보 확인 페이지****" << endl;
	cout << "이름 : " << name << endl;
	cout << "핸드폰 번호 : " << phone << endl;
	cout << "주소 : " << address << endl;
	cout << "현재까지 구매한 물건의 수 : " << productCount << endl;
	cout << "현재 코인 : " << coin << endl;
	showMyFeat();
	system("cls");
	return;
}
void User::showMyFeat()
{
	/*************************************************************************
	- 김가림
	- Function   : showMyfeat
	- Input      : None
	- Output     : None
	- Proceduere : 사용자의 정보를 보여준다
	- 수정 날짜  : (15.12.01) 색 추가
	*************************************************************************/
	cout << endl;
	cout << "CUTY [" << feat1_cuty << "]" << endl;
	for (int i = 0; i < feat1_cuty / 5; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "■";
		Sleep(25);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << endl;

	cout << "SEXY [" << feat2_sexy << "]" << endl;
	for (int i = 0; i < feat2_sexy / 5; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "■";
		Sleep(25);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << endl;

	cout << "FORMAL [" << feat3_formal << "]" << endl;
	for (int i = 0; i < feat3_formal / 5; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "■";
		Sleep(25);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << endl;

	cout << "CASUAL [" << feat4_casual << "]" << endl;
	for (int i = 0; i < feat4_casual / 5; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "■";
		Sleep(25);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << endl;
	getch();

}
void User::coinCharge()
{
	/*************************************************************************
	- 김가림(15.11.26)
	- Function   : coinCharge
	- Input      : None
	- Output     : None
	- Proceduere : 사용자의 전화번호와 같은 번호를 입력하면 코인 충전 성공
	- 수정 날짜  :
	*************************************************************************/
	cin.sync();
	int tempCoin = 0;
	string tempPhone;
	cout << endl;
	cout << "**코인충전페이지**" << endl;
	cin.sync();
	cout << "얼마를 충전할 것인지 입력하세요 : " << endl;
	cin >> tempCoin;
	cin.sync();
	cout << "개인 확인을 위해 전화번호를 입력해주세요 : " << endl;
	cin >> tempPhone;
	while (tempPhone != phone)
	{
		cout << "잘못된 전화번호를 입력하셨습니다." << endl;
		cout << "정확한 번호를 입력해주세요 : ";
		cin >> tempPhone;
	}
	cin.sync();
	cout << "인증에 성공하셨습니다." << endl;
	coin += tempCoin;
	vec_user.at(userIndex).coin += tempCoin;
	cout << "현재 잔액 : " << coin << endl;
	saveData();
	getch();
	system("cls");
}
bool User::logOut()
{
	system("cls");
	saveData();
	return true;
}
void User::shoppingCartPayment()
{
	/*************************************************************************
	- 김가림(2015.12.01)
	- Function   : shoppingCartPayment
	- Input      : None
	- Output     : None
	- Proceduere : 장바구니에 들어있는 상품을 주문, 결제한다.
	- 수정 날짜  :
	윤재문(2015.12.05)
	-주문서 양식에 맞게 출력하도록 수정
	-결제완료시 쇼핑카트 비우도록 구현
	김가림(2015. 12.13)
	-주문 후 상품의 해당 상품의 누적 구매 수 올라가도록 수정
	*************************************************************************/

	cout << "장바구니에 있는 상품 결제" << endl;
	int totalCost = 0;         //배송비를 포함한 총 가격

	char isEqualAddress;
	char isEqualPhone;
	char isPayment;

	string userAddress;
	string userPhone;

	Order tempOrder;

	ProductInfo tempProduct;
	cout << "a.주문상품 확인" << endl;
	for (int i = 0; i < vec_shoppingCart.size(); i++)
	{
		tempProduct = vec_shoppingCart.at(i);
		cout << i + 1 << "번 째 상품" << endl;
		cout << "상품명: " << tempProduct.name << endl;
		cout << "가격 : " << tempProduct.cost << endl;
		cout << "사이즈 : " << tempProduct.size << endl;
		totalCost += tempProduct.cost;
		cout << endl;
	}

	cout << "상품 가격 : " << totalCost << "원" << endl;
	totalCost += 2500;
	cout << "배송비를 포함한 전체 가격 : " << totalCost << "원" << endl;

	cout << "b. 배송지, 주문자 정보 확인" << endl;
	cout << "기존 주소와 일치합니까 ? (y/n)" << endl;
	cout << "기존 주소 : ";
	cout << address << endl;
	cin >> isEqualAddress;
	if (isEqualAddress == 'n')
	{
		cout << "새로운 주소를 입력해주세요" << endl;
		getline(cin, userAddress);
	}
	else
		userAddress = address;
	cout << endl;

	cout << "전화번호 : " << phone << endl;
	cout << "주문자 전화번호와 일치합니까 ?(y/n)" << endl;
	cin >> isEqualPhone;
	if (isEqualPhone == 'n')
	{
		cout << "새로운 주문자 전화번호를 입력해주세요" << endl;
		cin >> userPhone;
	}
	else
		userPhone = phone;

	cout << endl;

	cout << "c. 결제 정보" << endl;
	cout << "사용자의 현재 코인 : " << coin << endl;
	if (coin < totalCost)
	{
		cout << "coin이 부족합니다. 충전을 해주세요" << endl;
		Sleep(3000);
		return;
	}
	cout << "결제 후 코인 : " << coin - totalCost << endl;
	cout << "결제하시겠습니까? (y/n)" << endl;
	cin >> isPayment;

	if (isPayment == 'n')
	{
		cout << "결제를 취소합니다." << endl;
		Sleep(3000);
		return;
	}
	vec_user.at(userIndex).coin -= totalCost;      //사용자 코인 차감

	for (int i = 0; i < vec_shoppingCart.size(); i++)   //주문서 생성
	{
		tempProduct = vec_shoppingCart.at(i);
		if (i==0)
			tempOrder.productName =tempProduct.name;
		else 
			tempOrder.productName += "," + tempProduct.name;
	}
	tempOrder.isDelivered = false;
	tempOrder.productNum = vec_shoppingCart.size();
	if (vec_shoppingCart.size()==1)
		tempOrder.productSize = vec_shoppingCart.at(0).size;
	else
		tempOrder.productSize = vec_shoppingCart.at(0).size+"외"+itos(vec_shoppingCart.size()-1)+"개";
	tempOrder.totalPrice = totalCost;
	tempOrder.userAddress = userAddress;
	tempOrder.userName = name;
	tempOrder.userPhone = userPhone;
	vec_order.push_back(tempOrder);

	for (int i = 0; i < vec_shoppingCart.size(); i++)   //사용자 정보 수정
	{
		tempProduct = vec_shoppingCart.at(i);
		int tempNum;

		tempNum = (vec_user.at(userIndex).productCount)*(vec_user.at(userIndex).feat1_cuty) + tempProduct.feat1_cuty;
		vec_user.at(userIndex).feat1_cuty = tempNum / (vec_user.at(userIndex).productCount + 1);

		///feat2
		tempNum = (vec_user.at(userIndex).productCount)*(vec_user.at(userIndex).feat2_sexy) + tempProduct.feat2_sexy;
		vec_user.at(userIndex).feat2_sexy = tempNum / (vec_user.at(userIndex).productCount + 1);

		///feat3
		tempNum = (vec_user.at(userIndex).productCount)*(vec_user.at(userIndex).feat3_formal) + tempProduct.feat3_formal;
		vec_user.at(userIndex).feat3_formal = tempNum / (vec_user.at(userIndex).productCount + 1);

		///feat4
		tempNum = (vec_user.at(userIndex).productCount)*(vec_user.at(userIndex).feat4_casual) + tempProduct.feat4_casual;
		vec_user.at(userIndex).feat4_casual = tempNum / (vec_user.at(userIndex).productCount + 1);

		vec_user.at(userIndex).productCount++;
	}

	for (int i = 0; i < vec_shoppingCart.size(); i++)			//주문 후 상품의 재고, 판매량 수정
	{
		tempProduct = vec_shoppingCart.at(i);
		for (int j = 0; j < vec_product.size(); j++)
		{
			if (tempProduct.name == vec_product.at(j).name)
			{
				vec_product.at(j).stock--;
				vec_product.at(j).sellNumber++;
			}
		}
	}

	feat1_cuty = vec_user.at(userIndex).feat1_cuty;
	feat2_sexy = vec_user.at(userIndex).feat2_sexy;
	feat3_formal = vec_user.at(userIndex).feat3_formal;
	feat4_casual = vec_user.at(userIndex).feat4_casual;
	productCount = vec_user.at(userIndex).productCount;
	coin = vec_user.at(userIndex).coin;
	vec_shoppingCart.clear();
	saveData();
}
void User::recommendProduct()
{
	/*************************************************************************
	- 김가림(15.11.30)
	- Function   : recommendProduct
	- Input      : None
	- Output     : None
	- Proceduere : 일치율이 높은 상품은 menuProduct페이지 상단에 보여준다
	- 수정 날짜  :
	윤재문(15.12.06)
	-코드 전체를 admin의 search와 비슷하게 수정
	-temp벡터에 추천결과를 담고 키보드를 이용하여 페이지,상품선택이 가능하도록
	수정
	*************************************************************************/
	
	string search;
	vector <int> temp; //검색된 결과를 담는 벡터
	int productIndex = -1;
	int page = 1;	//페이지표시를 위한 변수
	int point = 0;	//상품 선택을 위한 변수
	int check;
	system("cls");
	for (int i = 0; i < vec_product.size(); i++)
	{
		if (calculationFeat(i) >= 85)
		{
			temp.push_back(i);
		}
	}
	if (temp.size() != 0)	//검색된 상품이 있으면
	{
		while (1)
		{
			/**********검색결과 출력부분**********/
			gotoxy(1, 1);
			char key;
			setColor("blue");
			cout << "돌아가기: backspace       자세히보기: spacebar" << endl;
			cout << "이젠페이지: left          다음페이지: right  " << endl;
			cout << "상품선택: up, down        \n" << endl;
			setColor("white");
			cout << "총" << temp.size() << "상품이 추천되었습니다!!" << endl;
			for (int i = 10 * (page - 1); i < page * 10; i++)
			{
				if (i < temp.size())
				{
					if (i % 10 == point)
					{
						setColor("red");
						cout << temp.at(i) + 1 << "번 상품: " << vec_product.at(temp.at(i)).name << endl;
						check = temp.at(i);
						setColor("white");
					}
					else
						cout << temp.at(i) + 1 << "번 상품: " << vec_product.at(temp.at(i)).name << endl;
				}
			}
			gotoxy(1, 17);
			cout << page << "/" << (temp.size() - 1) / 10 + 1;	//페이지 표시
			/***************키보드조작부분***********/
			key = getch();
			if (key == 8)
			{
				system("cls");
				return;
			}
			else if (key == 75 && page != 1)   //left arrow
			{
				page--;
				point = 0;
				system("cls");
			}
			else if (key == 72 && point != 0)   //down arrow
				point--;
			else if (key == 77 && page != ((temp.size() - 1) / 10) + 1)   //right arrow
			{
				page++;
				point = 0;
				system("cls");
			}
			else if (key == 80 && point != 9)   //up arrrow
			{
				if (page == (temp.size() / 10) + 1 && point == (temp.size() % 10) - 1)   //상품이 10개미만인경우 마지막 상품까지만 가리킴
				{
					//do noting
				}
				else
					point++;
			}
			else if (key == 32)
			{
				Product temp(vec_product.at(check));
				temp.detailInfo(userIndex);
			}
		}
	}
}
void User::showShoppingCart()
{
	/*************************************************************************
	- 김가림(15.12.05)
	- Function   : showShoppingCart()
	- Input      : proudctIndex
	- Output     : concordanceRate
	- Proceduere : product의 Index를 받아와서 user와의 일치율을 계산해서 return
	- 수정 날짜  : 김가림(15.12.13)장바구니가 비었을 때 명시
	*************************************************************************/

	ProductInfo tempProduct;
	cout << "***쇼핑카트***" << endl << endl;
	if (vec_shoppingCart.empty() == true)
		cout << "장바구니가 비었습니다" << endl;
	for (int i = 0; i < vec_shoppingCart.size(); i++)
	{
		tempProduct = vec_shoppingCart.at(i);
		cout << i + 1 << "번 째 상품" << endl;
		cout << "상품명: " << tempProduct.name << endl;
		cout << "가격 : " << tempProduct.cost << endl;
		cout << "사이즈 : " << tempProduct.size << endl;
		cout << endl;
	}
	cout << "주문을 원하시면 스페이스를 눌러주세요" << endl;
	cout << "뒤로가기는 백스페이스" << endl;
	while (1)
	{
		char key = getch();
		if (key == 32)
		{
			if (vec_shoppingCart.size() == 0)
			{
				cout << "장바구니에 상품이 없습니다\n";
				Sleep(1000);
				system("cls");
				return;
			}
			else
				shoppingCartPayment();
		}
		else if (key == 8)
		{
			system("cls");
			return;
		}
	}
}
int User::calculationFeat(int productIndex)
{
	/*************************************************************************
	- 김가림(15.11.30)
	- Function   : calculationFeat
	- Input      : proudctIndex
	- Output     : concordanceRate
	- Proceduere : product의 Index를 받아와서 user와의 일치율을 계산해서 return
	- 수정 날짜  :
	*************************************************************************/

	int error[4];
	int sumError, concordanceRate;
	error[0] = feat1_cuty - vec_product.at(productIndex).feat1_cuty;
	error[1] = feat2_sexy - vec_product.at(productIndex).feat2_sexy;
	error[2] = feat3_formal - vec_product.at(productIndex).feat3_formal;
	error[3] = feat4_casual - vec_product.at(productIndex).feat4_casual;

	for (int i = 0; i < 4; i++)
	{
		if (error[i] < 0)
			error[i] = -error[i];
	}
	sumError = error[0] + error[1] + error[2] + error[3];
	sumError /= 4;
	concordanceRate = 100 - sumError;
	return concordanceRate;
}
void User::showSellNumber()
{
	/*************************************************************************
	- 윤재문(15.12.08)
	- Function   : showSellNumber
	- Input      : None
	- Output     : None
	- Proceduere : 판매량이 높은 순으로 상품을 나열해줌
	- 수정 날짜  :
	*************************************************************************/
	system("cls");
	int flag=0;
	vector <ProductInfo> temp = vec_product;
	vector <int> result;
	for (int i = 0; i < temp.size(); i++)
	{
		for (int j = 0; j<temp.size(); j++)
		{
			if (temp.at(j).sellNumber>temp.at(flag).sellNumber)
			{
				flag = j;
			}
		}
		result.push_back(flag);
		temp.at(flag).sellNumber = -1;
	}
	int page = 1;
	int point = 0;
	int check;
	system("cls");
	while (1)
	{
		/**********검색결과 출력부분**********/
		gotoxy(1, 1);
		char key;
		setColor("blue");
		setColor("blue");
		cout << "돌아가기: backspace       자세히보기: spacebar" << endl;
		cout << "이전페이지: left          다음페이지: right  " << endl;
		cout << "상품선택: up, down        " << endl;
		setColor("white");
		setColor("white");
		for (int i = 10 * (page - 1); i < page * 10; i++)
		{
			if (i < result.size())
			{
				if (i % 10 == point)
				{
					setColor("red");
					cout << result.at(i) + 1 << "번 상품: " << vec_product.at(result.at(i)).name << "  판매량:" << vec_product.at(result.at(i)).sellNumber<< endl;
					check = result.at(i);
					setColor("white");
				}
				else
					cout << result.at(i) + 1 << "번 상품: " << vec_product.at(result.at(i)).name << "  판매량:" << vec_product.at(result.at(i)).sellNumber<< endl;
			}
		}
		gotoxy(1, 16);
		cout << page << "/" << (result.size() - 1) / 10 + 1;	//페이지 표시
		/***************키보드조작부분***********/
		key = getch();
		if (key == 8)
		{
			system("cls");
			return;
		}
		else if (key == 75 && page != 1)   //left arrow
		{
			page--;
			point = 0;
			system("cls");
		}
		else if (key == 72 && point != 0)   //down arrow
			point--;
		else if (key == 77 && page != ((temp.size() - 1) / 10) + 1)   //right arrow
		{
			page++;
			point = 0;
			system("cls");
		}
		else if (key == 80 && point != 9)   //up arrrow
		{
			if (page == (temp.size() / 10) + 1 && point == (temp.size() % 10) - 1)   //상품이 10개미만인경우 마지막 상품까지만 가리킴
			{
				//do noting
			}
			else
				point++;
		}
		else if (key == 32)	//spacebar
		{
			Product temp(vec_product.at(check));
			temp.detailInfo(userIndex);
		}
		Sleep(30);
	}
}
void Admin::getOrder()
{
	/*************************************************************************
	- 김가림(15.11.30)
	- Function   : getOrder
	- Input      : none
	- Output     : none
	- Proceduere : 관리자가 현재까지의 주문서를 모두 볼 수 있는 페이지
	- 수정 날짜  :
	*************************************************************************/

	cout << "**주문서 확인 페이지**";
	for (int i = 0; i < vec_order.size(); i++)
	{
		cout << "[주문서 " << i + 1 << "]" << endl;
		cout << "주문자 : " << vec_order.at(i).userName << endl;
		cout << "배송지 : " << vec_order.at(i).userAddress << endl;
		cout << "주문자 번호 : " << vec_order.at(i).userPhone << endl;
		cout << "상품명 : " << vec_order.at(i).productName << endl;
		cout << "주문 수량 : " << vec_order.at(i).productNum << endl;
		cout << "상품 사이즈 " << vec_order.at(i).productSize << endl;
		if (vec_order.at(i).isDelivered == true)
			cout << "배송 여부 : 배송 완료" << endl;
		else
			cout << "배송 여부 : 배송중" << endl;
		cout << endl << endl;
	}
	char inputChar;
	cout << "일괄 배송여부를 수정하시겠습니까?(y/n) " << endl;
	cin >> inputChar;
	if (inputChar == 'y')
	{
		for (int i = 0; i < vec_order.size(); i++)
		{
			vec_order.at(i).isDelivered = true;
		}
		cout << "모든 배송을 완료하였습니다." << endl;
	}
	saveData();
}
void Admin::menuProduct()
{
	/*************************************************************************
	- 윤재문(15.11.22)
	- Function   : menuProduct
	- Input      : vector <ProductInfo> vec
	- Output     : None
	- Proceduere : 모든 상품들을 나열하여 보여줌
	- 수정 날짜  : 
	윤재문(15.11.28)- 10개씩 1페이지로 나누어 보여주도록 수정
	윤재문(15.11.29)- 숫자입력에서 키보드로 조작하도록 수정
	윤재문(15.12.08)- 판매량이 높은순으로 볼수있는 메뉴추가
					- 재고량이 10이하인 상품을 볼수있는 메뉴추가
	*************************************************************************/

	int page = 1;
	int point = 0;
	int check;
	system("cls");
	while (1)
	{
		/*************목록 출력**************/
		gotoxy(1, 1);
		char key;
		setColor("blue");
		cout << "돌아가기: backspace       자세히보기: spacebar" << endl;
		cout << "이전페이지: left          다음페이지: right   " << endl;
		cout << "상품선택: up, down        판매량보기: h            재고량보기: s" << endl;
		setColor("white");
		for (int i = 10 * (page - 1); i < page * 10; i++)
		{
			if (i < vec_product.size())
			{
				if (i % 10 == point)
				{
					setColor("red");
					cout << i + 1 << ": 제품명: " << vec_product.at(i).name << endl;
					check = i;
					setColor("white");
				}
				else
					cout << i + 1 << ": 제품명: " << vec_product.at(i).name << endl;
			}
		}
		gotoxy(1, 15);
		cout << page << "/" << (vec_product.size()-1) / 10 + 1;	//페이지 표시
		/************키보드조작 부분*********/
		key = getch();
		if (key == 8)
		{
			system("cls");
			return;
		}
		else if (key == 75 && page != 1)   //left arrow
		{
			page--;
			point = 0;
			system("cls");
		}
		else if (key == 72 && point != 0)   //down arrow
			point--;
		else if (key == 77 && page != ((vec_product.size()-1) / 10) + 1)   //right arrow
		{
			page++;
			point = 0;
			system("cls");
		}
		else if (key == 80 && point != 9)   //up arrrow
		{
			if (page == (vec_product.size() / 10) + 1 && point == (vec_product.size() % 10) - 1)   //상품이 10개미만인경우 마지막 상품까지만 가리킴
			{
				//do noting
			}
			else
				point++;
		}
		else if (key == 32)	//spacebar
		{
			Product temp(vec_product.at(check));
			temp.detailInfo();
			productEdit(check);
		}
		else if (key == 'h'||key=='H')
		{
			showSellNumber();
		}
		else if (key == 's' || key == 'S')
		{
			showStock();
		}
		Sleep(30);
	}

}
void Admin::searchProduct()
{
	/*************************************************************************
	- 윤재문(15.11.22)
	- Function   : searchProduct
	- Input      : vector <ProductInfo> vec
	- Output     : None
	- Proceduere : 상품명으로 검색
	- 수정 날짜  : 
	윤재문(15.11.28)
	- 상품명중 일부만 포함해도 검색가능하도록 수정
	- 총 검색된 상품수 출력추가
	- 키보드로 조작하도록 구현
	윤재문(15.12.05)
	-검색한 상품정보 수정가능하도록 구현
	*************************************************************************/
	string search;
	vector <int> temp; //검색된 결과를 담는 벡터
	int productIndex = -1;
	int page = 1;	//페이지표시를 위한 변수
	int point = 0;	//상품 선택을 위한 변수
	int check;		
	system("cls");
	cout << "상품명을 입력해 주세요 >>";
	cin >> search;
	/*******검색된 결과 저장******/
	for (int i = 0; i < vec_product.size(); i++)
	{
		if (vec_product.at(i).name.find(search) != vec_product.at(i).name.npos)
		{
			temp.push_back(productIndex = i);
		}
	}
	if (temp.size() != 0)	//검색된 상품이 있으면
	{
		while (1)
		{
			/**********검색결과 출력부분**********/
			gotoxy(1, 1);
			char key;
			setColor("blue");
			cout << "돌아가기: backspace       자세히보기: spacebar" << endl;
			cout << "이전페이지: left          다음페이지: right  " << endl;
			cout << "상품선택: up, down        " << endl;
			setColor("white");
			cout << "" << search << "" << "에 대한 검색결과:" << "총" << temp.size() << "상품이 검색되었습니다." << endl;
			for (int i = 10 * (page - 1); i < page * 10; i++)
			{
				if (i < temp.size())
				{
					if (i % 10 == point)
					{
						setColor("red");
						cout << temp.at(i) + 1 << "번 상품: " << vec_product.at(temp.at(i)).name << endl;
						check = temp.at(i);
						setColor("white");
					}
					else
						cout << temp.at(i) + 1 << "번 상품: " << vec_product.at(temp.at(i)).name << endl;
				}
			}
			gotoxy(1, 16);
			cout << page << "/" << (temp.size()-1) / 10 + 1;	//페이지 표시
			/***************키보드조작부분***********/
			key = getch();
			if (key == 8)
			{
				system("cls");
				return;
			}
			else if (key == 75 && page != 1)   //left arrow
			{
				page--;
				point = 0;
				system("cls");
			}
			else if (key == 72 && point != 0)   //down arrow
				point--;
			else if (key == 77 && page != ((temp.size()-1) / 10) + 1)   //right arrow
			{
				page++;
				point = 0;
				system("cls");
			}
			else if (key == 80 && point != 9)   //up arrrow
			{
				if (page == (temp.size() / 10) + 1 && point == (temp.size() % 10) - 1)   //상품이 10개미만인경우 마지막 상품까지만 가리킴
				{
					//do noting
				}
				else
					point++;
			}
			else if (key == 32)
			{
				Product temp(vec_product.at(check));
				temp.detailInfo();
				productEdit(check);
			}
		}
	}
}
void Admin::productEdit(int index)
{
	/*************************************************************************
	- 윤재문(15.12.05)
	- Function   : productEdit
	- Input      : int index
	- Output     : None
	- Proceduere : 상품의 벡터에서의 위치를 받아 해당상품 정보수정
	- 수정 날짜  :
	*************************************************************************/
	while (1)
	{
		setColor("blue");
		gotoxy(1, 1);
		cout << "돌아가기: backspace   상품삭제: del     상품입고: 1" << endl;
		cout << "가격조정: 2           사이즈조정 :3     성향조정: 4"<<endl;
		setColor("white");
		gotoxy(1, 15);
		cout << "                                \n";
		cout << "                                \n";
		cout << "                                \n";
		gotoxy(1, 15);
		char key;
		key = getch();
		if (key == 16)
		{
			vec_product.erase(vec_product.begin() + index);
		}
		else if (key == 49)
		{
			cout << "입고량입력";
			int a;
			cin >> a;
			vec_product.at(index).stock += a;
			break;
		}
		else if (key == 50)
		{
			cout << "가격입력";
			int a;
			cin >> a;
			vec_product.at(index).cost = a;
			break;
		}
		else if (key == 51)
		{
			cout << "사이즈입력";
			string a;
			cin >> a;
			vec_product.at(index).size = a;
			break;
		}
		else if (key == 52)
		{
			int a;
			cout << "cuty입력";
			cin >> a;
			vec_product.at(index).feat1_cuty = a;
			cout << "sexy입력";
			cin >> a;
			vec_product.at(index).feat2_sexy = a;
			cout << "formal입력";
			cin >> a;
			vec_product.at(index).feat3_formal = a;
			cout << "casual입력";
			cin >> a;
			vec_product.at(index).feat4_casual = a;
			break;
		}
		else if (key == 8)
		{
			saveData();
			break;
		}
		Sleep(100);
	}
		system("cls");
}
void Admin::addProduct()
{
	/*************************************************************************
	- 윤재문(15.11.25)
	- Function   : addProduct
	- Input      : None
	- Output     : None
	- Proceduere : 상품추가 기능
	- 수정 날짜  :
	*************************************************************************/
	string s;
	ProductInfo temp;
	cout << "돌아가기 : backspace  continue : anykey\n";
	char key;
	key = getch();
	if (key == 8)
		return;
	fflush(stdin);
	cout << "상품명: ";
	getline(cin, s);
	temp.name = s;
	cout << "재고량: ";
	getline(cin, s);
	temp.stock = stoi(s);
	cout << "가격: ";
	getline(cin, s);
	temp.cost = stoi(s);
	cout << "사이즈: ";
	getline(cin, s);
	temp.size = s;
	temp.sellNumber = 0;
	cout << "cuty: ";
	getline(cin, s);
	temp.feat1_cuty = stoi(s);
	cout << "sexy: ";
	getline(cin, s);
	temp.feat2_sexy = stoi(s);
	cout << "formal: ";
	getline(cin, s);
	temp.feat3_formal = stoi(s);
	cout << "casual: ";
	getline(cin, s);
	temp.feat4_casual = stoi(s);
	vec_product.push_back(temp);
	cout << "상품추가완료";
	saveData();
	Sleep(2000);
}
bool Admin::logOut()
{
	/*************************************************************************
	- 윤재문(15.12.05)
	- Function   : logOut
	- Input      : None
	- Output     : bool
	- Proceduere : 로그아웃 기능
	- 수정 날짜  :
	*************************************************************************/
	system("cls");
	saveData();
	return true;
}
void Admin::showSellNumber()
{
	/*************************************************************************
	- 윤재문(15.12.08)
	- Function   : showSellNumber
	- Input      : None
	- Output     : None
	- Proceduere : 판매량이 높은순으로 상품을 나열해줌
	- 수정 날짜  :
	*************************************************************************/
	system("cls");
	int flag = 0;
	vector <ProductInfo> temp = vec_product;
	vector <int> result;
	for (int i = 0; i < temp.size(); i++)
	{
		for (int j = 0; j<temp.size(); j++)
		{
			if (temp.at(j).sellNumber>temp.at(flag).sellNumber)
			{
				flag = j;
			}
		}
		result.push_back(flag);
		temp.at(flag).sellNumber = -1;
	}
	int page = 1;
	int point = 0;
	int check;
	system("cls");
	while (1)
	{
		/**********검색결과 출력부분**********/
		gotoxy(1, 1);
		char key;
		setColor("blue");
		setColor("blue");
		cout << "돌아가기: backspace       자세히보기: spacebar" << endl;
		cout << "이전페이지: left          다음페이지: right  " << endl;
		cout << "상품선택: up, down        " << endl;
		setColor("white");
		setColor("white");
		for (int i = 10 * (page - 1); i < page * 10; i++)
		{
			if (i < result.size())
			{
				if (i % 10 == point)
				{
					setColor("red");
					cout << result.at(i) + 1 << "번 상품: " << vec_product.at(result.at(i)).name << "  판매량:" << vec_product.at(result.at(i)).sellNumber << endl;
					check = result.at(i);
					setColor("white");
				}
				else
					cout << result.at(i) + 1 << "번 상품: " << vec_product.at(result.at(i)).name << "  판매량:" << vec_product.at(result.at(i)).sellNumber << endl;
			}
		}
		gotoxy(1, 16);
		cout << page << "/" << (result.size() - 1) / 10 + 1;	//페이지 표시
		/***************키보드조작부분***********/
		key = getch();
		if (key == 8)
		{
			system("cls");
			return;
		}
		else if (key == 75 && page != 1)   //left arrow
		{
			page--;
			point = 0;
			system("cls");
		}
		else if (key == 72 && point != 0)   //down arrow
			point--;
		else if (key == 77 && page != ((temp.size() - 1) / 10) + 1)   //right arrow
		{
			page++;
			point = 0;
			system("cls");
		}
		else if (key == 80 && point != 9)   //up arrrow
		{
			if (page == (temp.size() / 10) + 1 && point == (temp.size() % 10) - 1)   //상품이 10개미만인경우 마지막 상품까지만 가리킴
			{
				//do noting
			}
			else
				point++;
		}
		else if (key == 32)
		{
			Product temp(vec_product.at(check));
			temp.detailInfo();
			productEdit(check);
		}
		Sleep(30);
	}
}
void Admin::showStock()
{
	/*************************************************************************
	- 윤재문(15.12.08)
	- Function   : showSellNumber
	- Input      : None
	- Output     : None
	- Proceduere : 재고량이 10이하인 상품들을 보여줌
	- 수정 날짜  : 
	*************************************************************************/
	system("cls");
	int flag = 0;
	vector <int> result;
	for (int i = 0; i < vec_product.size(); i++)
	{
		if (vec_product.at(i).stock <= 10)
		{
			result.push_back(i);
		}
	}
	int page = 1;
	int point = 0;
	int check;
	system("cls");
	while (1)
	{
		/**********검색결과 출력부분**********/
		gotoxy(1, 1);
		char key;
		setColor("blue");
		cout << "돌아가기: backspace       자세히보기: spacebar" << endl;
		cout << "이전페이지: left          다음페이지: right  " << endl;
		cout << "상품선택: up, down        " << endl;
		setColor("white");
		for (int i = 10 * (page - 1); i < page * 10; i++)
		{
			if (i < result.size())
			{
				if (i % 10 == point)
				{
					setColor("red");
					cout << result.at(i) + 1 << "번 상품: " << vec_product.at(result.at(i)).name << "  재고량:" << vec_product.at(result.at(i)).stock << endl;
					check = result.at(i);
					setColor("white");
				}
				else
					cout << result.at(i) + 1 << "번 상품: " << vec_product.at(result.at(i)).name << "  재고량:" << vec_product.at(result.at(i)).stock << endl;
			}
		}
		gotoxy(1, 16);
		cout << page << "/" << (result.size() - 1) / 10 + 1;	//페이지 표시
		/***************키보드조작부분***********/
		key = getch();
		if (key == 8)
		{
			system("cls");
			return;
		}
		else if (key == 75 && page != 1)   //left arrow
		{
			page--;
			point = 0;
			system("cls");
		}
		else if (key == 72 && point != 0)   //down arrow
			point--;
		else if (key == 77 && page != ((result.size() - 1) / 10) + 1)   //right arrow
		{
			page++;
			point = 0;
			system("cls");
		}
		else if (key == 80 && point != 9)   //up arrrow
		{
			if (page == (result.size() / 10) + 1 && point == (result.size() % 10) - 1)   //상품이 10개미만인경우 마지막 상품까지만 가리킴
			{
				//do noting
			}
			else
				point++;
		}
		else if (key == 32)
		{
			Product temp(vec_product.at(check));
			temp.detailInfo();
			productEdit(check);
		}
		Sleep(30);
	}
}
Product::Product(ProductInfo product)
{
	/*************************************************************************
	- 김가림(15.12.05)
	- Function   : Product
	- Input      : productInfo
	- Output     : 
	- Proceduere : Product구조체의 생성자
	- 수정 날짜  : 
	*************************************************************************/

	this->name = product.name;
	this->stock = product.stock;
	this->cost = product.cost;
	this->size = product.size;
	this->sellNumber = product.sellNumber;
	this->feat1_cuty = product.feat1_cuty;
	this->feat2_sexy = product.feat2_sexy;
	this->feat3_formal = product.feat3_formal;
	this->feat4_casual = product.feat4_casual;
}
void Product::detailInfo(int userIndex)
{
	/*************************************************************************
	- 김가림(15.11.25)
	- Function   : detailInfo
	- Input      : userIndex
	- Output     : None
	- Proceduere : userIndex를 받아와서 해당 상품을 구매할지 아니면 장바구니에 넣을지를 결정
	- 수정 날짜  : 김가림(15.12.01) 장바구니에 넣는 기능 추가
				   김가림(15.12.13) 재고가 없을때는 재고가 없다는 화면 출력
	*************************************************************************/
	char inputKey;
	while (1)
	{
		system("cls");
		cout << "상품명 :  " << name << endl;
		cout << "가격   :  " << cost << endl;
		cout << "사이즈 :  " << size << endl;
		cout << "수량   :  " << stock << endl;
		showProductFeat(userIndex);

		
		if (stock < 1)
		{
			cout << "재고가 없습니다." << endl;
		}
		else
		{
			cout << "주문을 원하시면 1번을 눌러주세용" << endl;
			cout << "장바구니에 넣으시려면 2번을 눌러주세용" << endl;
			inputKey = getch();
			if (inputKey == '1')
				payment(userIndex);
			else if (inputKey == '2')
				inputShoppingCart();
		}
		inputKey = getch();
		if (inputKey == 8)
		{
			system("cls");
			return;
		}
	}
}
void Product::inputShoppingCart()
{
	/*************************************************************************
	- 김가림(15.12.05)
	- Function   : inputShoppingCart
	- Input      : 
	- Output     : 
	- Proceduere : 해당 product를 벡터에 저장
	- 수정 날짜  : 
	*************************************************************************/

	ProductInfo tempProduct;
	tempProduct.cost = cost;
	tempProduct.name = name;
	tempProduct.sellNumber = sellNumber;
	tempProduct.size = size;
	tempProduct.stock = stock;
	tempProduct.feat1_cuty = feat1_cuty;
	tempProduct.feat2_sexy = feat2_sexy;
	tempProduct.feat3_formal = feat3_formal;
	tempProduct.feat4_casual = feat4_casual;

	vec_shoppingCart.push_back(tempProduct);
	//saveData();
}
void Product::detailInfo()
{
	/*************************************************************************
	- 김가림(15.12.05)
	- Function   : detailInfo
	- Input      : 
	- Output     : 
	- Proceduere : 상품의 정보를 보여준다(관리자용)
	- 수정 날짜  : 
	*************************************************************************/

	system("cls");
	gotoxy(1, 6);
	cout << "상품명 :  " << name << endl;
	cout << "가격   :  " << cost << endl;
	cout << "사이즈 :  " << size << endl;
	cout << "수량   :  " << stock << endl;
	cout << "판매량 :  " << sellNumber << endl;
	cout << "cuty   :  " << feat1_cuty << endl;
	cout << "sexy   :  " << feat2_sexy << endl;
	cout << "formal :  " << feat3_formal << endl;
	cout << "casual :  " << feat4_casual << endl;
}
void Product::showProductFeat(int userIndex)
{
	/*************************************************************************
	- 김가림(15.12.05)
	- Function   : showProductFeat
	- Input      : userIndex
	- Output     : None
	- Proceduere : 해당 상품과 사용자의 일치율을 계산해서 그래프로 보여줌
	- 수정 날짜  : (15.12.10) 색 추가
	*************************************************************************/

	int error[4];
	int sumError;
	int concordanceRate;

	cout << "*CUTY*" << endl;
	//상품 정보
	for (int i = 0; i < feat1_cuty / 5; i++)  
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "■";
		Sleep(5);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << endl;
	//사용자 정보
	for (int i = 0; i < vec_user.at(userIndex).feat1_cuty / 5; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "■";
		Sleep(5);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << endl << endl;

	cout << "*SEXY*" << endl;
	for (int i = 0; i < feat2_sexy / 5; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "■";
		Sleep(5);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << endl;
	for (int i = 0; i < vec_user.at(userIndex).feat2_sexy / 5; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "■";
		Sleep(5);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << endl << endl;

	cout << "*FORMAL*" << endl;
	for (int i = 0; i < feat3_formal / 5; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "■";
		Sleep(5);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << endl;

	for (int i = 0; i < vec_user.at(userIndex).feat3_formal / 5; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "■";
		Sleep(5);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << endl << endl;
	cout << "*CASUAL*" << endl;
	for (int i = 0; i < feat4_casual / 5; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "■";
		Sleep(5);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << endl;

	for (int i = 0; i < vec_user.at(userIndex).feat4_casual / 5; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "■";
		Sleep(5);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << endl << endl;

	error[0] = feat1_cuty - vec_user.at(userIndex).feat1_cuty;
	error[1] = feat2_sexy - vec_user.at(userIndex).feat2_sexy;
	error[2] = feat3_formal - vec_user.at(userIndex).feat3_formal;
	error[3] = feat4_casual - vec_user.at(userIndex).feat4_casual;

	for (int i = 0; i < 4; i++)
	{
		if (error[i] < 0)
			error[i] = -error[i];
	}
	sumError = error[0] + error[1] + error[2] + error[3];
	sumError /= 4;
	concordanceRate = 100 - sumError;
	cout << "해당 옷과 고객님과의 성향";
	cout << "일치율은 " << concordanceRate << "% 입니다" << endl;
	//	Sleep(3000);
}
void Product::payment(int userIndex)
{
	system("cls");
	/*************************************************************************
	- 김가림(15.11.25)
	- Function   : payment
	- Input      : userIndex
	- Output     : None
	- Proceduere : 해당 상품 구매 / 결제 페이지
	- 수정 날짜  : 구매한 상품의 재고와 판매량수 조절
	*************************************************************************/

	int buyNum;				//몇개 사는지 정보
	int totalCost;			//배송비를 포함한 총 가격

	char isEqualAddress;
	char isEqualPhone;
	char isPayment;

	string userAddress;
	string userPhone;

	Order tempOrder;

	cout << "***상품 주문/결제 페이지***" << endl;
	cout << "a.주문상품 확인" << endl;
	cout << "상품명 : " << name << endl;
	cout << "상품 사이즈 : " << size << endl;
	while (1)
	{
		cout << "수량을 입력해주세요" << endl;
		cin >> buyNum;
		if (buyNum <= stock)
		{
			break;
		}
		else
		{
			cout << "재고량보다 많습니다." << endl;
		}
	}
	cout << "가격 : " << cost*buyNum << "원" << endl;
	cout << "배송비 : 2500원" << endl;
	totalCost = cost*buyNum + 2500;
	cout << "총 가격 : " << totalCost << "원" << endl << endl;
	cout << "b. 배송지, 주문자 정보 확인" << endl;
	cout << "기존 주소와 일치합니까 ? (y/n)" << endl;
	cout << "기존 주소 : ";
	cout << vec_user.at(userIndex).address << endl;
	cin.sync();
	cin >> isEqualAddress;
	if (isEqualAddress == 'n')
	{
		cout << "새로운 주소를 입력해주세요" << endl;
		cin.sync();
		getline(cin, userAddress);
	}
	else
		userAddress = vec_user.at(userIndex).address;
	cout << endl;

	cout << "전화번호 : " << vec_user.at(userIndex).phone << endl;
	cout << "주문자 전화번호와 일치합니까 ?(y/n)" << endl;
	cin >> isEqualPhone;
	if (isEqualPhone == 'n')
	{
		cout << "새로운 주문자 전화번호를 입력해주세요" << endl;
		cin >> userPhone;
	}
	else
		userPhone = vec_user.at(userIndex).phone;

	cout << endl;
	cout << "c. 결제 정보" << endl;
	cout << "사용자의 현재 코인 : " << vec_user.at(userIndex).coin << endl;
	if (vec_user.at(userIndex).coin < totalCost)
	{
		cout << "coin이 부족합니다. 충전을 해주세요" << endl;
		Sleep(3000);
		return;
	}
	cout << "결제 후 코인 : " << vec_user.at(userIndex).coin - totalCost << endl;
	cout << "결제하시겠습니까? (y/n)" << endl;
	cin >> isPayment;

	if (isPayment == 'n')
	{
		cout << "결제를 취소합니다." << endl;
		Sleep(3000);
		return;
	}

	for (int i = 0; i < vec_product.size(); i++)
	{
		if (name == vec_product.at(i).name)
		{
			vec_product.at(i).stock -= buyNum;
			vec_product.at(i).sellNumber += buyNum;
		}
	}

	vec_user.at(userIndex).coin -= totalCost;		//사용자 코인 차감
	vec_user.at(userIndex).productCount += buyNum;	//사용자 총 구매 상품수 증가
	replaceFeat(userIndex, buyNum);					//사용자 성향 조절
	stock -= buyNum;
	sellNumber += buyNum;
	///order구조체 생성
	tempOrder.productName = name;
	tempOrder.productNum = buyNum;
	tempOrder.productSize = size;
	tempOrder.totalPrice = totalCost;
	tempOrder.userAddress = userAddress;
	tempOrder.userName = vec_user.at(userIndex).name;
	tempOrder.userPhone = userPhone;
	tempOrder.isDelivered = false;
	vec_order.push_back(tempOrder);
	//vector에 push_back함
	saveData();
}
void Product::replaceFeat(int userIndex, int buyNum)
{
	/*************************************************************************
	- 김가림(15.11.25)
	- Function   : replaceFeat
	- Input      : userIndex, buyNum
	- Output     : None
	- Proceduere : 상품을 결제한 후 상품의 정보를 내 정보에 누적 반영
	- 수정 날짜  : 
	*************************************************************************/

	int tempNum;
	cout << "**성향 수정**" << endl;
	cout << "기존 성향" << endl;
	cout << "cuty : " << vec_user.at(userIndex).feat1_cuty << endl;
	cout << "sexy : " << vec_user.at(userIndex).feat2_sexy << endl;
	cout << "formal : " << vec_user.at(userIndex).feat3_formal << endl;
	cout << "casual : " << vec_user.at(userIndex).feat4_casual << endl;

	///feat1
	tempNum = (vec_user.at(userIndex).productCount)*(vec_user.at(userIndex).feat1_cuty) + (buyNum*feat1_cuty);
	vec_user.at(userIndex).feat1_cuty = tempNum / (vec_user.at(userIndex).productCount + buyNum);

	///feat2
	tempNum = (vec_user.at(userIndex).productCount)*(vec_user.at(userIndex).feat2_sexy) + (buyNum*feat2_sexy);
	vec_user.at(userIndex).feat2_sexy = tempNum / (vec_user.at(userIndex).productCount + buyNum);

	///feat3
	tempNum = (vec_user.at(userIndex).productCount)*(vec_user.at(userIndex).feat3_formal) + (buyNum*feat3_formal);
	vec_user.at(userIndex).feat3_formal = tempNum / (vec_user.at(userIndex).productCount + buyNum);

	///feat4
	tempNum = (vec_user.at(userIndex).productCount)*(vec_user.at(userIndex).feat4_casual) + (buyNum*feat4_casual);
	vec_user.at(userIndex).feat4_casual = tempNum / (vec_user.at(userIndex).productCount + buyNum);

	cout << "수정 후 성향" << endl;
	cout << "cuty : " << vec_user.at(userIndex).feat1_cuty << endl;
	cout << "sexy : " << vec_user.at(userIndex).feat2_sexy << endl;
	cout << "formal : " << vec_user.at(userIndex).feat3_formal << endl;
	cout << "casual : " << vec_user.at(userIndex).feat4_casual << endl;

}
int main()
{
	showStartingScreen();
	getch();
	system("cls");
	Start a;
	return 0;
}
