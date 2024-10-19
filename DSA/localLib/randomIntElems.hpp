#ifndef RANDOM_INT_ELEMS
#define RANDOM_INT_ELEMS


#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>

// generate elements within a range
class RandomIntElements{
    private:
        int lower, upper, max_size;
        std::vector<int> random_numbers;

        void generateRandomElements(){
            int range_size = upper- lower + 1;
            int min_size = range_size / 2;
            if(this->max_size == -1){
                std::srand(std::time(0));
                this->max_size = min_size + (std::rand() % (range_size - min_size + 1)); 
            }

            for(int i=0; i < this->max_size; ++i){
                int num = this->lower + (std::rand() % range_size);
                this->random_numbers.push_back(num);
            }
        }

        void printHelper() const{
            for(int num : this->random_numbers){
                std::cout<< num << " ";
            }
            std::cout<<std::endl;
        }

    public:
        RandomIntElements(int lower_bound, int upper_bound, int max_s = -1){
            if(max_s < 0){
                std::cerr<<"Error : 'max_size' cannot be negative!";
                throw std::invalid_argument("Invalid max_size value");
            }
            lower = lower_bound;
            upper = upper_bound;
            max_size = max_s;

            if(upper < lower){
                std::swap(lower, upper);
            }

            this->generateRandomElements();
        }

        void printElements() const {
            this->printHelper();
        }

        std::vector<int> getRandomNumbers() const{
            return this->random_numbers;
        }

        int getNextRandomElement(){
            if(lower > upper){
                std::swap(lower, upper);
            }
            return lower + (std::rand() % (upper - lower + 1));
        }

        int getRandomElement() const{
            if(this->random_numbers.empty()){
                std::cerr<<"Error: No elements in the vector."<<std::endl;
                return -1;
            }
            int random_index = std::rand() % this->random_numbers.size();
            return this->random_numbers.at(random_index);
        }
};

#endif