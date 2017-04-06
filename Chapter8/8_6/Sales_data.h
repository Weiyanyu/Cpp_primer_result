#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>


class Sales_data{
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::istream &read(std::istream&, Sales_data&);
	friend std::ostream &print(std::ostream&, const Sales_data&);
public:
	Sales_data(const std::string &s, unsigned n, double p):
				bookNo(s),unit_sole(n),revenue(p*n) { }
	Sales_data():
		Sales_data("",0,0) { }
	Sales_data(std::string s):
				Sales_data(s,0,0) { }
	Sales_data(std::istream &is);
			
	std::string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data &);
private:
	inline
	double avg_price() const{
		return unit_sole ? revenue / unit_sole : 0;
	}
	std::string bookNo;
	unsigned unit_sole = 0;
	double revenue = 0.0;

};


	

Sales_data& Sales_data::combine(const Sales_data &rhs){
	unit_sole += rhs.unit_sole;
	revenue += rhs.revenue;
	return *this;
}

std::istream& read(std::istream &is,Sales_data &item){
	double price = 0;
	is >> item.bookNo >> item.unit_sole >> price;
	item.revenue = price * item.unit_sole;
	return is;
}

std::ostream& print(std::ostream &os,const Sales_data &item){
	os << item.isbn() << " " << item.unit_sole << " "
	   << item.revenue;
	return os;
}

Sales_data add(const Sales_data &lhs,const Sales_data &rhs){
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}





#endif
