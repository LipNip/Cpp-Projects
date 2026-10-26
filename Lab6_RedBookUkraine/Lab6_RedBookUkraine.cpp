#include <iostream>
#include <string>
using namespace std;

class Animals {
protected:
    string name;
    double age, weight;
    string habitat;
    int population;     
    string order, speciesName;
public:
    Animals() : name("No name"), age(0), weight(0), habitat("No habitat"), population(0), order("No order"), speciesName("No species name") {}
    Animals(string name, double age, double weight, string habitat, int population, string order, string speciesName) : name(name), age(age), weight(weight), habitat(habitat), population(population), order(order), speciesName(speciesName) {}
    virtual ~Animals() {}

    int getPopulation() const { return population; }
    string getOrder() const { return order; }
    string getSpeciesName() const { return speciesName; }
    
    virtual void print() const {
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Weight: " << weight << "\n";
        cout << "Habitat: " << habitat << "\n";
        cout << "Population: " << population << "\n";
        cout << "Order: " << order << "\n";
        cout << "Species name: " << speciesName << "\n";
    }
};

class Birds : public Animals {
protected:
    double wingspan;
    string featherColor;
    double flightAltitude;
public:
    Birds() : Animals(), wingspan(0), featherColor("No feather color"), flightAltitude(0) {}
    Birds(string name, double age, double weight, string habitat, int population, string order, string speciesName, double wingspan, string featherColor, double flightAltitude) :
        Animals(name, age, weight, habitat, population, order, speciesName), wingspan(wingspan), featherColor(featherColor), flightAltitude(flightAltitude) {}

    void print() const override {
        Animals::print();
        cout << "Wingspan: " << wingspan << "\n";
        cout << "Feather color: " << featherColor << "\n";
        cout << "Flight altitude: " << flightAltitude << "\n";
    }
};

class Reptiles : public Animals {
protected:
    string scaleType, movementType;
    double bodyTemperature;
public:
    Reptiles() : Animals(), scaleType("No scale type"), movementType("No movement type"), bodyTemperature(0) {}
    Reptiles(string name, double age, double weight, string habitat, int population, string order, string speciesName, string scaleType, string movementType, double bodyTemperature) :
        Animals(name, age, weight, habitat, population, order, speciesName), scaleType(scaleType), movementType(movementType), bodyTemperature(bodyTemperature) {}

    void print() const override {
        Animals::print();
        cout << "Scale type: " << scaleType << "\n";
        cout << "Movement type: " << movementType << "\n";
        cout << "Body temperature: " << bodyTemperature << "\n";
    }
};

class Mammals : public Animals {
protected:
    string furType;
    double gestationPeriod;
    bool hasMammaryGlands;
public:
    Mammals() : Animals(), furType("No fur type"), gestationPeriod(0), hasMammaryGlands(false) {}
    Mammals(string name, double age, double weight, string habitat, int population, string order, string speciesName, string furType, double gestationPeriod, bool hasMammaryGlands) :
        Animals(name, age, weight, habitat, population, order, speciesName), furType(furType), gestationPeriod(gestationPeriod), hasMammaryGlands(hasMammaryGlands) {}

    void print() const override {
        Animals::print();
        cout << "Fur type: " << furType << "\n";
        cout << "Gestation period (days): " << gestationPeriod << "\n";
        cout << "Has mammary glands: " << (hasMammaryGlands ? "Yes" : "No") << "\n";
    }
};

class Hawk : public Birds {
private:
    double visualAcuity, clawLength;
public:
    Hawk() : Birds(), visualAcuity(0), clawLength(0) {}
    Hawk(string name, double age, double weight, string habitat, int population, string order, string speciesName, double wingspan, string featherColor, double flightAltitude, double visualAcuity, double clawLength) :
        Birds(name, age, weight, habitat, population, order, speciesName, wingspan, featherColor, flightAltitude), visualAcuity(visualAcuity), clawLength(clawLength) {}

    void print() const override {
        Birds::print();
        cout << "Visual acuity: " << visualAcuity << "\n";
        cout << "Claw length: " << clawLength << "\n";
    }
};

class Falcon : public Birds {
private:
    double maxDivingSpeed;
    string beakShape;
public:
    Falcon() : Birds(), maxDivingSpeed(0), beakShape("No beak shape") {}
    Falcon(string name, double age, double weight, string habitat, int population, string order, string speciesName, double wingspan, string featherColor, double flightAltitude, double maxDivingSpeed, string beakShape) :
        Birds(name, age, weight, habitat, population, order, speciesName, wingspan, featherColor, flightAltitude), maxDivingSpeed(maxDivingSpeed), beakShape(beakShape) {}

    void print() const override {
        Birds::print();
        cout << "Max diving speed: " << maxDivingSpeed << "\n";
        cout << "Beak shape: " << beakShape << "\n";
    }
};

class GrassSnake : public Reptiles {
private:
    bool hasYellowHeadSpots;
    string preferredPrey;
public:
    GrassSnake() : Reptiles(), hasYellowHeadSpots(false), preferredPrey("No preferred prey") {}
    GrassSnake(string name, double age, double weight, string habitat, int population, string order, string speciesName, string scaleType, string movementType, double bodyTemperature, bool hasYellowHeadSpots, string preferredPrey) :
        Reptiles(name, age, weight, habitat, population, order, speciesName, scaleType, movementType, bodyTemperature), hasYellowHeadSpots(hasYellowHeadSpots), preferredPrey(preferredPrey) {}

    void print() const override {
        Reptiles::print();
        cout << "Has yellow head spots: " << (hasYellowHeadSpots ? "Yes" : "No") << "\n";
        cout << "Preferred prey: " << preferredPrey << "\n";
    }
};

class Viper : public Reptiles {
private:
    string venomToxicityLevel;
    bool hasZigzagPattern;
public:
    Viper() : Reptiles(), venomToxicityLevel("No toxicity level"), hasZigzagPattern(false) {}
    Viper(string name, double age, double weight, string habitat, int population, string order, string speciesName, string scaleType, string movementType, double bodyTemperature, string venomToxicityLevel, bool hasZigzagPattern) :
        Reptiles(name, age, weight, habitat, population, order, speciesName, scaleType, movementType, bodyTemperature), venomToxicityLevel(venomToxicityLevel), hasZigzagPattern(hasZigzagPattern) {}

    void print() const override {
        Reptiles::print();
        cout << "Venom toxicity level: " << venomToxicityLevel << "\n";
        cout << "Has zigzag pattern: " << (hasZigzagPattern ? "Yes" : "No") << "\n";
    }
};

class Marten : public Mammals {
private:
    bool isTreeClimber;
    double tailLength;
public:
    Marten() : Mammals(), isTreeClimber(false), tailLength(0) {}
    Marten(string name, double age, double weight, string habitat, int population, string order, string speciesName, string furType, double gestationPeriod, bool hasMammaryGlands, bool isTreeClimber, double tailLength) :
        Mammals(name, age, weight, habitat, population, order, speciesName, furType, gestationPeriod, hasMammaryGlands), isTreeClimber(isTreeClimber), tailLength(tailLength) {}

    void print() const override {
        Mammals::print();
        cout << "Is tree climber: " << (isTreeClimber ? "Yes" : "No") << "\n";
        cout << "Tail length: " << tailLength << "\n";
    }
};

class Felidae : public Mammals {
private:
    bool hasRetractableClaws;
    bool hasNightVision;
public:
    Felidae() : Mammals(), hasRetractableClaws(false), hasNightVision(false) {}
    Felidae(string name, double age, double weight, string habitat, int population, string order, string speciesName, string furType, double gestationPeriod, bool hasMammaryGlands, bool hasRetractableClaws, bool hasNightVision) :
        Mammals(name, age, weight, habitat, population, order, speciesName, furType, gestationPeriod, hasMammaryGlands), hasRetractableClaws(hasRetractableClaws), hasNightVision(hasNightVision) {}

    void print() const override {
        Mammals::print();
        cout << "Has retractable claws: " << (hasRetractableClaws ? "Yes" : "No") << "\n";
        cout << "Has night vision: " << (hasNightVision ? "Yes" : "No") << "\n";
    }
};

class RedBook {
    Hawk* hawks;
    Falcon* falcons;
    GrassSnake* grassSnakes;
    Viper* vipers;
    Marten* martens;
    Felidae* felidaeCats;
    int sizeHawk, sizeFalcon, sizeGrassSnake, sizeViper, sizeMarten, sizeFelidae;

    // Збирає всіх тварин в один спільний список, щоб у методах пошуку не писати по 6 окремих циклів для кожного виду тварин
    void collectAllAnimals(Animals** all) const {
        int j = 0;
        for (int i = 0; i < sizeHawk; i++) all[j++] = &hawks[i];
        for (int i = 0; i < sizeFalcon; i++) all[j++] = &falcons[i];
        for (int i = 0; i < sizeGrassSnake; i++) all[j++] = &grassSnakes[i];
        for (int i = 0; i < sizeViper; i++) all[j++] = &vipers[i];
        for (int i = 0; i < sizeMarten; i++) all[j++] = &martens[i];
        for (int i = 0; i < sizeFelidae; i++) all[j++] = &felidaeCats[i];
    }
public:
    RedBook(Hawk* hawks, int sizeHawk, Falcon* falcons, int sizeFalcon, GrassSnake* grassSnakes, int sizeGrassSnake, Viper* vipers, int sizeViper, Marten* martens, int sizeMarten, Felidae* felidaeCats, int sizeFelidae) {
        this->sizeHawk = sizeHawk;
        this->hawks = new Hawk[sizeHawk];
        for (int i = 0; i < sizeHawk; i++) this->hawks[i] = hawks[i];

        this->sizeFalcon = sizeFalcon;
        this->falcons = new Falcon[sizeFalcon];
        for (int i = 0; i < sizeFalcon; i++) this->falcons[i] = falcons[i];

        this->sizeGrassSnake = sizeGrassSnake;
        this->grassSnakes = new GrassSnake[sizeGrassSnake];
        for (int i = 0; i < sizeGrassSnake; i++) this->grassSnakes[i] = grassSnakes[i];

        this->sizeViper = sizeViper;
        this->vipers = new Viper[sizeViper];
        for (int i = 0; i < sizeViper; i++) this->vipers[i] = vipers[i];

        this->sizeMarten = sizeMarten;
        this->martens = new Marten[sizeMarten];
        for (int i = 0; i < sizeMarten; i++) this->martens[i] = martens[i];

        this->sizeFelidae = sizeFelidae;
        this->felidaeCats = new Felidae[sizeFelidae];
        for (int i = 0; i < sizeFelidae; i++) this->felidaeCats[i] = felidaeCats[i];
    }

    ~RedBook() {
        delete[] hawks;
        delete[] falcons;
        delete[] grassSnakes;
        delete[] vipers;
        delete[] martens;
        delete[] felidaeCats;
    }

    //а)	Виводити інформацію про всіх плазунів, птахів, ссавців;
    void printAll()const {
        int total = sizeHawk + sizeFalcon + sizeGrassSnake + sizeViper + sizeMarten + sizeFelidae;
        if (total == 0) return;
        Animals** all = new Animals* [total];
        collectAllAnimals(all);
        for (int i = 0; i < total; i++)
        {
            all[i]->print();
            cout << "-------------------\n";
        }
        delete[] all;
    }

    //б)	Виводити інформацію по конкретному ряду;
    void printByOrder(string order)const {
        int total = sizeHawk + sizeFalcon + sizeGrassSnake + sizeViper + sizeMarten + sizeFelidae;
        if (total == 0) return;
        Animals** all = new Animals* [total];
        collectAllAnimals(all);
        for (int i = 0; i < total; i++) 
        {
            if (all[i]->getOrder() == order) {
                all[i]->print();
                cout << "-------------------\n";
            }
        }
        delete[] all;
    }

    //в)	Виводити інформацію по конкретному виду;
    void printBySpecies(string species)const {
        int total = sizeHawk + sizeFalcon + sizeGrassSnake + sizeViper + sizeMarten + sizeFelidae;
        if (total == 0) return;
        Animals** all = new Animals * [total];
        collectAllAnimals(all);
        for (int i = 0; i < total; i++)
        {
            if (all[i]->getSpeciesName() == species) {
                all[i]->print();
                cout << "-------------------\n";
            }
        }
        delete[] all;
    }

    //г)	Вивести інформацію про тварин, чисельність виду яких є найменшою.
    void printMinPopulation()const {
        int total = sizeHawk + sizeFalcon + sizeGrassSnake + sizeViper + sizeMarten + sizeFelidae;
        if (total == 0) return;
        Animals** all = new Animals* [total];
        collectAllAnimals(all);
        int minPop = all[0]->getPopulation();
        for (int i = 1; i < total; i++)
        {
            if (all[i]->getPopulation() < minPop) {
                minPop = all[i]->getPopulation();
            }
        }
        for (int i = 0; i < total; i++)
        {
            if (all[i]->getPopulation() == minPop) {
                all[i]->print();
                cout << "-----------------------\n";
            }
        }
        delete[] all;
    }

    //д)	Вивести інформацію про тварин, чисельність виду яких є найбільшою.
    void printMaxPopulation()const {
        int total = sizeHawk + sizeFalcon + sizeGrassSnake + sizeViper + sizeMarten + sizeFelidae;
        if (total == 0) return;
        Animals** all = new Animals * [total];
        collectAllAnimals(all);
        int maxPop = all[0]->getPopulation();
        for (int i = 1; i < total; i++)
        {
            if (all[i]->getPopulation() > maxPop) {
                maxPop = all[i]->getPopulation();
            }
        }
        for (int i = 0; i < total; i++)
        {
            if (all[i]->getPopulation() == maxPop) {
                all[i]->print();
                cout << "-----------------------\n";
            }
        }
        delete[] all;
    }
};

int main()
{
    Hawk hawks[] = {
        Hawk("Northern Goshawk", 3.0, 1.2, "Forests", 120, "Falconiformes", "Hawk", 1.1, "Brown", 600.0, 2.5, 3.2)
    };
    Falcon falcons[] = {
        Falcon("Peregrine Falcon", 2.0, 0.9, "Mountains", 45, "Falconiformes", "Falcon", 1.0, "Grey", 1000.0, 320.0, "Hooked")
    };
    GrassSnake snakes[] = {
        GrassSnake("Grass Snake", 1.5, 0.4, "Wetlands", 1500, "Squamata", "Grass Snake", "Smooth", "Slithering", 22.0, true, "Frogs")
    };
    Viper vipers[] = {
        Viper("Meadow Viper", 4.0, 0.25, "Steppes", 210, "Squamata", "Viper", "Scaly", "Slithering", 24.0, "High", true)
    };
    Marten martens[] = {
        Marten("Pine Marten", 3.0, 1.5, "Forests", 350, "Carnivora", "Marten", "Dense", 28.0, true, true, 22.5)
    };
    Felidae cats[] = {
        Felidae("Wildcat", 5.0, 6.0, "Forests", 45, "Carnivora", "Felidae", "Soft", 68.0, true, true, true)
    };

    RedBook redBook(hawks, 1, falcons, 1, snakes, 1, vipers, 1, martens, 1, cats, 1);

    redBook.printAll();
    redBook.printByOrder("Falconiformes");  
    redBook.printBySpecies("Grass Snake"); 
    redBook.printMinPopulation();
    redBook.printMaxPopulation();

    cout << "\n\n";
    return 0;
}