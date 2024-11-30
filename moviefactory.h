#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include "classics.h"
#include "drama.h"
#include "comedy.h"
#include <string>

class MovieFactory {
private:
    static bool convertToInt(std::string str, int& num, std::string errorType){
        try{
            num = stoi(str);
        }catch(std::invalid_argument e){
            std::cout << "ERROR: " << str << " Invalid " << errorType << ". Try Again." << std::endl;
            return false;
        }
        return true;
    }

    //true when input is a number
    static bool contains_int(std::string str){
        for(char ch: str){
            if(isdigit(ch)){
                return true;
            }
        }
        return false;
    }
public:
    static Movie* createMovies(std::string& line){
        // command in form [TransactionType], [stock], [Director], [Title], [MajorActorFirstName MajorActorLastName Month Year or Year]
        std::stringstream stream(line); 

        // holds each token seprated by a comma in this string array
        std::string commandData[5]; //{[TransactionType], [stock], [Director], [Title], [MajorActorFirstName MajorActorLastName Month Year or Year]}
        int i = 0;
        while(!stream.eof()){
            std::string curr;
            getline(stream,curr,',');
            commandData[i] = curr;
            i++;
        }

        char type;
        int stock;
        std::string director;
        std::string title;
        std::string actorFirstName, actorLastName;
        int month, year;
        type = commandData[0][0];

        if(type != 'F' && type != 'D' && type != 'C'){
            std::cout << "ERROR: " << type <<" Invalid Genre. Try Again." << std::endl;
            return nullptr;
        }

        if(!convertToInt(commandData[1], stock, "stock has to be an int")) return nullptr;
        

        if(stock < 0){
            std::cout << "ERROR: " << stock << " Invalid stock amount. Try Again." << std::endl;
            return nullptr;
        }

        director = commandData[2].substr(1);
        if(contains_int(director)) {
            std::cout << "ERROR: " << director << " Invalid director name. Try Again." << std::endl;
            return nullptr;
        }

        title = commandData[3].substr(1);

        std::stringstream classicsStream(commandData[4]);
        
        switch(type){
            case 'F':
                if(!convertToInt(commandData[4], year, "year specified")) return nullptr;
                if(year < 0){
                    std::cout << "ERROR: " << year << " Invalid year. Try Again." << std::endl;
                    return nullptr;
                }
                return new Comedy(stock, director, title, year);
            case 'D':
                if(!convertToInt(commandData[4], year, "year specified")) return nullptr;
                if(year < 0){
                    std::cout << "ERROR: " << year << " Invalid year. Try Again." << std::endl;
                    return nullptr;
                }
                return new Drama(stock, director, title, year);
            case 'C':
                classicsStream >> actorFirstName >> actorLastName >> month >> year;
                if(year < 0){
                    std::cout << "ERROR: " << year << " Invalid year. Try Again." << std::endl;
                    return nullptr;
                }
                return new Classics(stock, director, title,actorFirstName,actorLastName,month, year);
        }
        return nullptr;
    }
};

#endif