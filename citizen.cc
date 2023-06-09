#include <citizen/citizen.h>
#include <string>
#include <stdexcept>

using namespace citizen;
using namespace std;

Citizen::Citizen( CitizenType _type, string last_name, string first_name, string middle_name, string school_name, int shool_ID_number, bool large_fam ) {
	this->_type = _type;
	this->last_name = last_name;
	this->first_name = first_name;
	this->middle_name = middle_name;
	this->school_name = school_name;
	this->shool_ID_number = shool_ID_number;
	this->large_fam = large_fam;
}

Citizen::Citizen( CitizenType _type, string last_name, string first_name, string middle_name, string university_name, int student_ID_number, double average_grade ) {
	this->_type = _type;
	this->last_name = last_name;
	this->first_name = first_name;
	this->middle_name = middle_name;
	this->university_name = university_name;
	this->student_ID_number = student_ID_number;
	this->average_grade = average_grade;
	if (average_grade < 0.0 || average_grade > 5.0)
		throw invalid_argument("[Citizen()] Invalid constructor type.");
		
}
Citizen::Citizen( CitizenType _type, string last_name, string first_name, string middle_name, string snils, int experience ) {
	this->_type = _type;
	this->last_name = last_name;
	this->first_name = first_name;
	this->middle_name = middle_name;
	this->snils = snils;
	this->experience = experience;
	if (experience < 0)
		throw invalid_argument("[Citizen()] Invalid constructor type.");
}

Citizen::Citizen() : _type(CitizenType::Schoolboy), last_name("Johnny"), first_name("Dale"), middle_name("Rudio"), school_name("Aston_school"), shool_ID_number(123456), large_fam(false) { }

double Citizen::payment() {
	double payment = 0.0;
	switch (_type) {
	case CitizenType::Schoolboy:
	{
		if (large_fam == true)
			payment = 0.5 * min_wage;
		break;
	}

	case CitizenType::Student:
	{
		if (average_grade >= 3.5 && average_grade <= 5.0)
			payment = (-0.2 + 0.2 * average_grade) * min_wage;
		break;
	}

	case CitizenType::Pensioner:
		if (experience >= 5 && experience <= 30)
			payment = (0.4 + 0.12 * experience) * min_wage;
		if (experience > 30)
			payment = 5 * min_wage;
		break;
	}
	return payment;
}

CitizenType Citizen::get_type() const {
	return _type;
}
string Citizen::get_last_name() const {
	return last_name;
}
string Citizen::get_first_name() const {
	return first_name;
}
string Citizen::get_middle_name() const {
	return middle_name;
}
string Citizen::get_school_name() const {
	return school_name;
}
int Citizen::get_school_ID_number() const {
	return shool_ID_number;
}
bool Citizen::get_large_fam() const {
	return large_fam;
}
string Citizen::get_university_name() const {
	return university_name;
}
int Citizen::get_student_ID_number() const {
	return student_ID_number;
}
double Citizen::get_average_grade() const {
	return average_grade;
}
string Citizen::get_snils() const {
	return snils;
}
int Citizen::get_experience() const {
	return experience;
}

void Citizen::set_citizen_type(CitizenType _type) {
	this->_type = _type;
}

void Citizen::set_large_fam(bool large_fam) {
	this->large_fam = large_fam;
}
void Citizen::set_average_grade(double average_grade) {
	this->average_grade = average_grade;
	if (average_grade < 0.0 || average_grade > 5.0)
		throw invalid_argument("[set_average_grade()] Invalid set type.");
}
void Citizen::set_experience(int experience) {
	this->experience = experience;
	if (experience < 0)
		throw invalid_argument("[set_experience()] Invalid set type.");
}
void Citizen::set_min_wage(int min_wage) {
	this->min_wage = min_wage;
}


bool citizen::operator==(const Citizen& lhs, const Citizen& rhs) {
	return
		lhs.get_type() == rhs.get_type() &&
		lhs.get_last_name() == rhs.get_last_name() &&
		lhs.get_first_name() == rhs.get_first_name() &&
		lhs.get_middle_name() == rhs.get_middle_name() &&
		lhs.get_school_name() == rhs.get_school_name() &&
		lhs.get_university_name() == rhs.get_university_name() &&
		lhs.get_school_ID_number() == rhs.get_school_ID_number() &&
		lhs.get_student_ID_number() == rhs.get_student_ID_number() &&
		lhs.get_snils() == rhs.get_snils() &&
		lhs.get_average_grade() == rhs.get_average_grade() &&
		lhs.get_experience() == rhs.get_experience() &&
		lhs.get_large_fam() == rhs.get_large_fam();
}
