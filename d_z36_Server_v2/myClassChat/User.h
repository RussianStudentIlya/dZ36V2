#pragma once
#include <string>
///using namespace std;

class User
{
private:
	std::string _login; // логин пользователя
	std::string _last_name; // Фамилия пользователя
	const std::string _name; // Имя пользователя
	std::string _email;
	const std::string _patronymic; // Отчество
	std::string _hash_password;  // пароль


public:
	User(const std::string& last_name, const std::string& name, const std::string& patronymic, const std::string& email, const std::string &hash_password, const std::string& login):
	_last_name(last_name), _name(name), _patronymic(patronymic), _email(email), _login(login)
	{
		setUserPassword(hash_password);
	}

    User(){}


	const std::string& getLastName() const { return this->_last_name; } /// прочитать фамилию пользователя
	void setLastName(const std::string& last_name)  { _last_name = last_name; }/// изменит

	const std::string& getName() const { return this->_name; } /// прочитать имя пользователя
	///void setName(const string& name) { _name = name; }/// изменит

	const std::string& getPatronymic() const { return this->_patronymic; } /// прочитать отчество пользователя
	///void setName(const string& name) { _name = name; }/// изменит

	const std::string& getEmail() const { return this->_email; } /// прочитать email
	void setEmail(const std::string& email) { _email = email; }/// изменит

	const std::string& getUserPassword() const { return this->_hash_password; } /// прочитать пароль пользователя
	void setUserPassword(const std::string& password) /// изменит пароль пользователя 
	{
		int sum = 0;
		for (int i = 0; i < password.size(); ++i)
		{
			sum += password[i];
		}

		this->_hash_password = std::to_string(sum);
	}

	std::string get_hash_Login(const std::string& password)
	{
		int sum = 0;
		for (int i = 0; i < password.size(); ++i)
		{
			sum += password[i];
		}

		return std::to_string(sum);
	}

	const std::string& getLogin() const { return this->_login; } /// прочитать логин
	void setLogin(const std::string& login) { this->_login = login; } // изменить логин
};
