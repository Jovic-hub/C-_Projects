
#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds {
    class Food {
        char m_itemName[31];
        int m_time;
        int m_calories;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, int calories, int time);
        void display()const;
        bool isValid()const;
        double calories()const;
    };
}

#endif 
