#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <exception>

class InvalidSize : public std::exception {
public:
    InvalidSize() = default;

    const char *what() const noexcept override {
            return "Invalid Size!";
    }
};
class InvalidGender : public std::exception {
public:
    InvalidGender() = default;

    const char *what() const noexcept override {
            return "Invalid Gender!";
    }
};
enum class Haine {
    Pantaloni, Tricouri, Adidasi
};
class Clothes{
    int marime;
    std:: string gen;
public:
    Clothes(int marime_, std::string gen_) : marime(marime_), gen(std::move(gen_)){
        if (marime < 0) throw InvalidSize();
        if (gen != "feminin" and gen != "masculin" and gen != "unisex") throw InvalidGender();
    }
    Clothes() {}

    virtual ~Clothes() = default;
    virtual Haine getTip() const = 0;

    virtual std::string material() const = 0;
    virtual std::string brand() const = 0;

    //getter
    int getMarime() const {
        return marime;
    }
    std::string getGen() const {
        return gen;
    }

    //setter
    void setMarime(int new_marime){
        marime = new_marime;

    }
    void setGen(std::string new_gen){
        gen = std::move(new_gen);
    }

    virtual void print(std::ostream &siaut) const {
        siaut << "Aceasta haina are marimea " << marime << ", este de firma "<< brand() << " si e din "<< material();
    }
};

std::ostream& operator<<(std:: ostream &fout, const Clothes *haine){
    haine->print(fout);
    return fout;
}

class Pantaloni:public Clothes {
    int nrBuzunare;
    std:: string tip;
public:
    Pantaloni(int marime1, std::string gen1, int nrBuzunare1, std:: string tip1) : Clothes(marime1, std::move(gen1)), nrBuzunare(nrBuzunare1), tip (std:: move(tip1)){}
    Pantaloni() {}

    //supraincarcare metode virtuale pure
    Haine getTip() const override{
        return Haine::Pantaloni;
    }
    std::string material() const override{
        return "Blug";
    }
    std::string brand() const override {
        return "Levi's";
    }
    //getters
    int nrBuz() const{
        return nrBuzunare;
    }
    std::string tipul() const {
        return tip;
    }
    //setters
    void set_nrBuzu(int nouNrBuz) {
        nrBuzunare = nouNrBuz;
    }
    void set_tip(std::string tipul_) {
        tip = tipul_;
    }

    void print(std:: ostream &fout) const override{
        print(fout);
        std::cout << "\n" << "Acest pantalon are " << nrBuz() <<" buzunare";
        std::cout << "\n" << "Acest pantalon este " << tipul();
    }

    //cc
    Pantaloni(const Pantaloni &pant) : Clothes(pant.getMarime(), pant.getGen()), nrBuzunare(pant.nrBuz()), tip(pant.tipul()){}

    // incarcare pe op=
    Pantaloni& operator=(const Pantaloni &rhs) {
        if (this != &rhs) {
           Clothes ::operator=(rhs);
           nrBuzunare = rhs.nrBuzunare;
           tip = rhs.tip;
        }
        return *this;
    }
};



class Tricouri:public Clothes {
    std:: string tip; //maneca scurta sau lunga
public:
    Tricouri(int marime2, std::string gen2, std:: string tip2) : Clothes(marime2, std::move(gen2)), tip (std:: move(tip2)){}
    Tricouri() {}

    //supraincarcare metode virtuale pure
    Haine getTip() const override{
        return Haine::Tricouri;
    }
    std::string material() const override{
        return "Bumbac";
    }
    std::string brand() const override {
        return "Puma";
    }
    //getters
    std::string tipul() const {
        return tip;
    }
    //setters
    void set_tip(std::string tipul_) {
        tip = tipul_;
    }

    void print(std:: ostream &fout) const override{
        print(fout);
        std::cout << "\n" << "Acest Tricou este pentru " << tipul();
    }

    //cc
    Tricouri(const Tricouri &tric) : Clothes(tric.getMarime(), tric.getGen()), tip(tric.tipul()){}

    // incarcare pe op=
    Tricouri& operator=(const Tricouri &rhs) {
        if (this != &rhs) {
            Clothes ::operator=(rhs);
            tip = rhs.tip;
        }
        return *this;
    }
};


class Adidasi:public Clothes {
    std:: string talpa; //inalta, joasa
    std:: string tip;
public:
    Adidasi(int marime1, std::string gen1, std:: string tip1, std:: string talpa1) : Clothes(marime1, std::move(gen1)), tip (std:: move(tip1)), talpa (std:: move(talpa1)){}
    Adidasi() {}

    //supraincarcare metode virtuale pure
    Haine getTip() const override{
        return Haine::Adidasi;
    }
    std::string material() const override{
        return "Piele";
    }
    std::string brand() const override {
        return "Nike";
    }
    //getters
    std::string talpaa() const {
        return talpa;
    }
    std::string tipul() const {
        return tip;
    }
    //setters
    void set_talpa(std::string talpa_) {
        tip = talpa_;
    }
    void set_tip(std::string tipul_) {
        tip = tipul_;
    }

    void print(std:: ostream &fout) const override{
        print(fout);
        std::cout << "\n" << "Acest adidas are talpa" << talpaa();
        std::cout << "\n" << "Acest adidas este " << tipul();
    }

    //cc
    Adidasi(const Adidasi &adi) : Clothes(adi.getMarime(), adi.getGen()), tip(adi.tipul()), talpa(adi.talpaa()){}

    // incarcare pe op=
    Adidasi& operator=(const Adidasi &rhs) {
        if (this != &rhs) {
            Clothes ::operator=(rhs);
            talpa = rhs.talpa;
            tip = rhs.tip;
        }
        return *this;
    }
};


class FashionStore{
  std::vector<std::shared_ptr<Clothes>> haine;
  FashionStore() = delete;
public:
    void addHaina( const std::shared_ptr<Clothes> &haina){
        haine.push_back(haina);
    }
    void printAllHaine (){
        for (auto it: haine){
            std::cout<<it<<"\n";
        }
    }
    void printAllTricouri() {
        for (auto it: haine){
            if (it->getTip() != Haine::Tricouri) continue;
            std::cout<<it<<"\n";
        }
    };
    void printAllAdidasi() {
        for (auto it: haine){
            if (it->getTip() != Haine::Adidasi) continue;
            std::cout<<it<<"\n";
        }
    }
    void printAllPants() {
        for (auto it: haine){
            if (it->getTip() != Haine::Pantaloni) continue;
            std::cout<<it<<"\n";
        }
    };
};





int main() {

}

