#include <iostream>

class Fraction {
private:
    int numerator_;
    int denominator_;

public:
    Fraction(int numerator, int denominator) {
        numerator_ = numerator;
        denominator_ = denominator;
    }

    bool operator==(const Fraction& other) const {
        return numerator_ * other.denominator_ == denominator_ * other.numerator_;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const {
        return numerator_ * other.denominator_ < denominator_* other.numerator_;
    }

    bool operator>(const Fraction& other) const {
        return other < *this;
    }

    bool operator<=(const Fraction& other) const {
        return !(other < *this);
    }

    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }

    Fraction operator+(const Fraction& other) const {
        int new_numerator = numerator_ * other.denominator_ + denominator_ * other.numerator_;
        int new_denominator = denominator_ * other.denominator_;
        return Fraction(new_numerator, new_denominator);
    }

    Fraction operator-(const Fraction& other) const {
        int new_numerator = numerator_ * other.denominator_ - denominator_ * other.numerator_;
        int new_denominator = denominator_ * other.denominator_;
        return Fraction(new_numerator, new_denominator);
    }

    Fraction operator*(const Fraction& other) const {
        int new_numerator = numerator_ * other.numerator_;
        int new_denominator = denominator_ * other.denominator_;
        return Fraction(new_numerator, new_denominator);
    }

    Fraction operator/(const Fraction& other) const {
        int new_numerator = numerator_ * other.denominator_;
        int new_denominator = denominator_ * other.numerator_;
        return Fraction(new_numerator, new_denominator);
    }

    Fraction operator-() const {
        return Fraction(-numerator_, denominator_);
    }

    Fraction& operator++() {
        numerator_ += denominator_;
        return *this;
    }

    Fraction operator++(int) {
        Fraction temp(*this);
        ++(*this);
        return temp;
    }

    Fraction& operator--() {
        numerator_ -= denominator_;
        return *this;
    }

    Fraction operator--(int) {
        Fraction temp(*this);
        --(*this);
        return temp;
    }

    void print() const {
        std::cout << numerator_ << "/" << denominator_ << std::endl;
    }
};

int main() {
    int num1, den1, num2, den2;
    std::cout << "Enter two fractions separated by a space: ";
    std::cin >> num1 >> den1 >> num2 >> den2;

    Fraction f1(num1, den1);
    Fraction f2(num2, den2);

    Fraction sum = f1 + f2;
    Fraction difference = f1 - f2;
    Fraction product = f1 * f2;
    Fraction quotient = f1 / f2;
    Fraction negation = -f1;
    Fraction post_increment = f1++;
    Fraction pre_increment = ++f1;
    Fraction post_decrement = f1--;
    Fraction pre_decrement = --f1;

    std::cout << "Sum: ";
    sum.print();
    std::cout << "Difference: ";
    difference.print();
    std::cout << "Product: ";
    product.print();