#include <iostream>
#include <string>
using namespace std;

class Animals {
protected:
    string name;
    double age, weight;
    string habitat;
public:
    Animals() : name("No name"), age(0), weight(0), habitat("No habitat") {}
    Animals(string name, double age, double weight, string habitat) : name(name), age(age), weight(weight), habitat(habitat) {}

    virtual void print() const {
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Weight: " << weight << "\n";
        cout << "Habitat: " << habitat << "\n";
    }
};

class Birds : public Animals {
protected:
    double wingspan;
    string featherColor;
    double flightAltitude;
public:
    Birds() : Animals(), wingspan(0), featherColor("No feather color"), flightAltitude(0) {}
    Birds(string name, double age, double weight, string habitat, double wingspan, string featherColor, double flightAltitude) :
        Animals(name, age, weight, habitat), wingspan(wingspan), featherColor(featherColor), flightAltitude(flightAltitude) {}

    void print() const override {
        Animals::print();
        cout << "Wingspan: " << wingspan << "\n";
        cout << "Feathe crolor: " << featherColor << "\n";
        cout << "Flight altitude: " << flightAltitude << "\n";
    }
};

class Reptiles : public Animals {
protected:
    string scaleType, movementType;
    double bodyTemperature;
public:
    Reptiles() : Animals(), scaleType("No scale type"), movementType("No movement type"), bodyTemperature(0) {}
    Reptiles(string name, double age, double weight, string habitat, string scaleType, string movementType, double bodyTemperature) :
        Animals(name, age, weight, habitat), scaleType(scaleType), movementType(movementType), bodyTemperature(bodyTemperature) {}

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
    Mammals(string name, double age, double weight, string habitat, string furType, double gestationPeriod, bool hasMammaryGlands) :
        Animals(name, age, weight, habitat), furType(furType), gestationPeriod(gestationPeriod), hasMammaryGlands(hasMammaryGlands) {}

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
    Hawk(string name, double age, double weight, string habitat, double wingspan, string featherColor, double flightAltitude, double visualAcuity, double clawLength) :
        Birds(name, age, weight, habitat, wingspan, featherColor, flightAltitude), visualAcuity(visualAcuity), clawLength(clawLength) {}

    void print() const override {
        Birds::print();
        cout << "Visual acuity " << visualAcuity << "\n";
        cout << "Claw length: " << clawLength << "\n";
    }
};

class Falcon : public Birds {
private:
    double maxDivingSpeed;
    string beakShape;
public:
    Falcon() : Birds(), maxDivingSpeed(0), beakShape("No beak shape") {}
    Falcon(string name, double age, double weight, string habitat, double wingspan, string featherColor, double flightAltitude, double maxDivingSpeed, string beakShape) :
        Birds(name, age, weight, habitat, wingspan, featherColor, flightAltitude), maxDivingSpeed(maxDivingSpeed), beakShape(beakShape) {}

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
    GrassSnake(string name, double age, double weight, string habitat, string scaleType, string movementType, double bodyTemperature, bool hasYellowHeadSpots, string preferredPrey) :
        Reptiles(name, age, weight, habitat, scaleType, movementType, bodyTemperature), hasYellowHeadSpots(hasYellowHeadSpots), preferredPrey(preferredPrey) {}

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
    Viper(string name, double age, double weight, string habitat, string scaleType, string movementType, double bodyTemperature, string venomToxicityLevel, bool hasZigzagPattern) :
        Reptiles(name, age, weight, habitat, scaleType, movementType, bodyTemperature), venomToxicityLevel(venomToxicityLevel), hasZigzagPattern(hasZigzagPattern) {}

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
    Marten(string name, double age, double weight, string habitat, string furType, double gestationPeriod, bool hasMammaryGlands, bool isTreeClimber, double tailLength) :
        Mammals(name, age, weight, habitat, furType, gestationPeriod, hasMammaryGlands), isTreeClimber(isTreeClimber), tailLength(tailLength) {}

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
    Felidae(string name, double age, double weight, string habitat, string furType, double gestationPeriod, bool hasMammaryGlands, bool hasRetractableClaws, bool hasNightVision) :
        Mammals(name, age, weight, habitat, furType, gestationPeriod, hasMammaryGlands), hasRetractableClaws(hasRetractableClaws), hasNightVision(hasNightVision) {}

    void print() const override {
        Mammals::print();
        cout << "Has retractable claws: " << (hasRetractableClaws ? "Yes" : "No") << "\n";
        cout << "Has night vision: " << (hasNightVision ? "Yes" : "No") << "\n";
    }
};

int main()
{

    cout << "\n\n";
    return 0;
}