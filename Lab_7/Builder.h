#pragma once

#include<iostream>;
#include<string>;
#include<memory>;


class Car {
private:

    std::string m_brand;
    std::string m_model;
    std::string m_color;
    std::string m_engine;
    int m_power = 0;
    int m_doorCount = 0;


public:

    void setBrand(std::string brand) {
        m_brand = brand;
    }

    void setModel(std::string model) {
        m_model = model;
    }

    void setColor(std::string color) {
        m_color = color;
    }

    void setEngine(std::string engine) {
        m_engine = engine;
    }

    void setPower(int power) {
        m_power = power;
    }

    void setDoors(int doorCount) {
        m_doorCount = doorCount;
    }

    void printInfo() const {
        std::cout << "������: " << m_brand << " " << m_model << '\n'
            << "����: " << m_color << '\n'
            << "���������: " << m_engine << '\n'
            << "��������: " << m_power << '\n'
            << "�����: " << m_doorCount << '\n';
    }

};



class CarBuilder {
public:
    virtual ~CarBuilder() = default;
    virtual void buildBrand() = 0;
    virtual void buildModel() = 0;
    virtual void buildColor() = 0;
    virtual void buildEngine() = 0;
    virtual void buildDoors() = 0;
    virtual std::unique_ptr<Car> getCar() = 0;
};



class SportsCarBuilder : public CarBuilder {
public:
    SportsCarBuilder() {
        m_car = std::make_unique<Car>();
    }

    void buildBrand() override {
        m_car->setBrand("�������");
    }

    void buildModel() override {
        m_car->setModel("������ ������ :)");
    }

    void buildColor() override {
        m_car->setColor("�������");
    }

    void buildEngine() override {
        m_car->setEngine("�����-����� ������");
        m_car->setPower(670);
    }

    void buildDoors() override {
        m_car->setDoors(2);
    }

    std::unique_ptr<Car> getCar() override {
        return std::move(m_car);
    }

private:
    std::unique_ptr<Car> m_car;
};



class FamilyCarBuilder : public CarBuilder {
public:
    FamilyCarBuilder() {
        m_car = std::make_unique<Car>();
    }

    void buildBrand() override {
        m_car->setBrand("������");
    }

    void buildModel() override {
        m_car->setModel("�����");
    }

    void buildColor() override {
        m_car->setColor("����������");
    }

    void buildEngine() override {
        m_car->setEngine("���������� ���������");
        m_car->setPower(301);
    }

    void buildDoors() override {
        m_car->setDoors(4);
    }

    std::unique_ptr<Car> getCar() override {
        return std::move(m_car);
    }

private:
    std::unique_ptr<Car> m_car;
};



// ��������, ������� ��������� ��������� �������������
class Director {
private:
    CarBuilder* m_builder;


public:
    void setBuilder(CarBuilder* builder) {
        m_builder = builder;
    }


    std::unique_ptr<Car> constructCar() {
        m_builder->buildBrand();
        m_builder->buildModel();
        m_builder->buildColor();
        m_builder->buildEngine();
        m_builder->buildDoors();
        return m_builder->getCar();
    }
};
