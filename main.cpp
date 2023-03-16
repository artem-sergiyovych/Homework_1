//1-st task from homework
#include <iostream>
#include <vector>
#include <numeric>

class Student {
private:
    int album_number;
    std::string name;
    std::string surname;
    std::vector<float> grades{4, 5, 3, 5, 2, 4, 3, 3};
    float mean_grade;

public:
    //This funtion in called a constructor
    Student(std::string input_name) {               //When we have params here, an object can't be created without inputting them
        name = input_name;
        std::cout << "an object was created\n";
    }

    //Antoher constructor without params
    Student() {                                      //It is another constructor because lack of parameters
        // cin, cout can be located here-> code jumps from main and waits
    }

    ///Setter for name
    void setName(std::string set_name) {
        name = set_name;                    //setter
    }

    ///Getter for name
    std::string getName() {
        return name;                        //getter
    }

    ///Setter for surname
    void setSurName(std::string set_surname) {
        surname = set_surname;                    //setter
    }

    ///Getter for surname
    std::string getSurName() {
        return surname;                        //getter
    }

    ///Setter for album number
    bool setAlbum(int set_album) {
        if (set_album > 9999 && set_album < 1000000) {
            album_number = set_album;
            return true;
        } else {
            album_number = NULL;
            std::cout << "Provided album number was not proper. Album number must contain from 5 to 6 digits."
                      << std::endl;
            std::cout << "Student`s id was autoset to " << album_number << std::endl;
            return false;
        }
    }

    ///Getter for album number
    int getAlbum() {
        return album_number;
    }


    //Add grade
    bool add_grade(float grade) {
        if (grade >= 2.0 && grade <= 5.0) {
            grades.push_back(grade);
            return true;
        }
        return false;
    }

    void add_few_grades() {
        std::cout << "Would you like to add some grades? Y&y/N&n" << std::endl;
        char desition;
        std::cin >> desition;
        bool runner = true;
        while (runner) {
            if (desition == 'Y' || desition == 'y') {
                std::cout << "press any letter to stop adding grades" << std::endl;
                float grade;
                while (std::cin >> grade) {
                    if (grade >= 2.0 && grade <= 5.0) {
                        grades.push_back(grade);
                    }
                }
                runner = false;
            } else if (desition == 'N' || desition == 'n') {
                std::cout << "You decided not to add marks" << std::endl;
                runner = false;
            } else {
                std::cout << "You wrote invalid char, try again" << std::endl;
                std::cin >> desition;
            }
        }
    }

    //Get mean grade
    float getMean() {
        float gradessum = 0;                                                  //Another option
        for (auto grade: grades) {                                          //float sum = std::accumulate(grades.begin(), grades.end(), 0.0f);
            gradessum += grade;                                             //return sum / grades.size();
        }
        mean_grade = gradessum / grades.size();
        return mean_grade;
    }

    //Bad marks checker
    void passing_control() {
        int j = 0;                      //calculator of bad marks
        for (auto grade: grades) {
            if (grade == 2) {
                j++;
            }
        }
        if (j <= 1) {
            std::cout << "Student passed" << std::endl;
        } else {
            std::cout << "Student did not pass" << std::endl;
        }
    }

    //Overall (CV)
    void print_overall() {
        std::cout << "Full name      -> " << name << ' ' << surname << std::endl;
        std::cout << "Grades         -> ";
        for (auto grade: grades)
            std::cout << grade << ' ';
        std::cout << std::endl;
        std::cout << "Album number   -> " << album_number << std::endl;
        std::cout << "Mean grade     -> " << getMean()
                  << std::endl;                            //101 why calling the mean private field brings wrong result?
        std::cout << "Passing status -> ";
        passing_control();                                   ///102 passing control as cout argument is unimplementable cuz
        ///102 passing_control() function is of a type void?
    }
};

void task1_execution() {
    ///Student student("Alex");
    Student student;
    //Setters
    student.setName("Albert");
    student.setSurName("Baboboba");
    student.setAlbum(88888);

    //Display
/*    std::cout << student.getName()<< ' ' << student.getSurName() << std::endl;
    std::cout << "Mean grade-> " << student.getMean() << std::endl;
    student.passing_control()*/;
    student.add_few_grades();
    student.print_overall();

}

class Complex {
private:
    float real;
    float im;
public:
    void set_im(float imnum) {
        im = imnum;
    }

    Complex(float realnum, float imnum) {

        real = realnum;
        im = imnum;
/*    if (real!=0 && im>0)
        std::cout << real << " + " << im << 'i' << std::endl;
    else if(real!=0 && im<0)
        std::cout << real << " - " << abs(im) << 'i' << std::endl;
    else if (real == 0)
        std::cout << im << 'i' << std::endl;
    else if (im == 0)
        std::cout << real << std::endl;*/
    }

    Complex(float realnum) {                     //Constructor without imaginary part
        real = realnum;
        //std::cout << real << std::endl;
    }

    std::string print() {
        if (real != 0 && im > 0)
            std::cout << real << " + " << im << "i" << std::endl;
        else if (real != 0 && im < 0)
            std::cout << real << " - " << abs(im) << "i" << std::endl;
    }

    Complex add(Complex b) {
        real += b.real;
        im += b.im;
        return Complex(real, im);
    }

};

void task2_execution() {
    Complex a(5, 5);
    Complex b(5);
    b.set_im(5);
    //b.get_num();
    Complex c = a.add(b);
    c.print();
}

int main() {
    char choice;
    std::cout << "Choose some option:\n"
                 "1 - Task 1\n"
                 "2 - Task 2" << std::endl;
    std::cin >> choice;
    switch (choice) {
        case '1': {
            task1_execution();
            break;
        }
        case '2': {
            task2_execution();
            break;
        }
    }
}