#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>
#include <sstream>
#include <time.h>

using namespace std;
typedef struct UserInfo
{
	string id;
	string password;
	string name;
	string phone;
	string address;
	int    coin;
	int productCount;
	int feat1_cuty;
	int feat2_sexy;
	int feat3_formal;
	int feat4_casual;
}UserInfo;
typedef struct ProductInfo
{
	string name;
	int stock; //재고
	int cost;
	string size;
	int sellNumber; //팔린양
	int feat1_cuty;
	int feat2_sexy;
	int feat3_formal;
	int feat4_casual;
}ProductInfo;
typedef struct Order
{
	string orderDate;
	string userName;
	string userPhone;
	string userAddress;
	/**받는사람의 이름, 전화번호 ,주소**/
	string productName;
	string productSize;
	int productNum;      //상품 몇개 주문하는지
	/** 상품 정보**/
	int totalPrice;      //배송비 포함 얼마인지
	/**현재 물건**/
	bool isDelivered;   //배송 여부
}Order;

vector <UserInfo> vec_user;
vector <ProductInfo> vec_product;
vector <Order> vec_order;
//장바구니기능(15.12.03)
vector <ProductInfo> vec_shoppingCart;

class User
{
private:
	string id;
	string password;
	string name;
	string phone;
	string address;
	int coin;
	int feat1_cuty;
	int feat2_sexy;
	int feat3_formal;
	int feat4_casual;
	int productCount; //지금까지 물품을 구입한 수량
	int userIndex;
public:
	User(){};
	User(int index);
	void searchProduct();
	void menuProduct();
	void myInfo();
	void showMyFeat();
	void coinCharge();
	bool logOut();
	void shoppingCartPayment();
	void recommendProduct();
	int calculationFeat(int productIndex);
	//장바구니기능(15.12.03)
	void showShoppingCart();
	void replaceFeat(int userIndex, int buyNum);
	void showSellNumber();
};
class Admin
{
public:
	void getOrder();
	void searchProduct();
	void menuProduct();///관리자도 상품 검색/목록 확인 가능하게
	void productEdit(int index);
	void addProduct();
	bool logOut();
	void showSellNumber();
	void showStock();
};
class Product
{
private:
	string name;
	int stock; //재고
	int cost;
	string size;
	int sellNumber; //팔린양
	int feat1_cuty;
	int feat2_sexy;
	int feat3_formal;
	int feat4_casual;
public:
	Product(ProductInfo product);
	void detailInfo();//관리자
	void detailInfo(int userIndex);//이용자
	void payment(int userIndex);
	void showProductFeat(int userIndex);
	void replaceFeat(int userIndex, int buyNum);
	//(15.12.03)장바구니기능추가
	void inputShoppingCart();
};
class Start
{
private:
	bool isAdmin;
public:
	Start();
	int login();
	void signUp();
	void menu(int userIndex);
	int isUserID(string _id);  //아이디가 존재하는지 확인 있다면 index를 return
	User currentUser;
	Admin currentAdmin;
	void signUpQuestion(int &cuty, int&sexy, int&formal, int&casual);
};

void setColor(string color);
void gotoxy(int x, int y);
string itos(int num);
