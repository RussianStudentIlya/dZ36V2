#include "Chat.h"

Chat::Chat(mySQL_db& dbConnect) : _dbConnect(dbConnect)
{
	_dbConnect.connect_DB(_dbConnect.get_dbName());

	if (_dbConnect.getConnectStatus() != true)
	{
		_dbConnect.create_DB(_dbConnect.get_dbName());
	}

    ///this->client = net_Client();
}

Chat::Chat() : _dbConnect()
{}

Chat::~Chat()
{
	delete tables[0];
	delete tables[1];
	delete tables[2];

    //delete user;
    //delete messag;
}

void Chat::startChat()
{
	if (_dbConnect.getConnectStatus())
	{
		tables[0] = new db_Table_Client(_dbConnect.getConnectStatus(), _dbConnect); // Создание таблицы clients исли она не существуют
		
		tables[1] = new db_Table_hPassword(_dbConnect.getConnectStatus(), _dbConnect); // Создание таблицы password_hash исли она не существуют
		
		tables[2] = new db_Table_Messages(_dbConnect.getConnectStatus(), _dbConnect); // Создать таблицу messages если она не существуют
		
		//tables[3] = new db_Table_Info_Messages(_dbConnect.getConnectStatus(), _dbConnect);// Создать таблицу info_messages если она не существуют

		/*---Если все таблицы созданы то чат старт---*/
		/*if (t_client.getStatusCreateTable() && t_messag.getStatusCreateTable() && t_h_password.getStatusCreateTable())
			this->_chatStart = true;
		else
			this->_chatStart = false;*/

		if (tables[0]->getStatusCreateTable() && tables[1]->getStatusCreateTable() && tables[2]->getStatusCreateTable())
			this->_chatStart = true;
		else
			this->_chatStart = false;
	}
}

const bool Chat::get_ChatStart() const
{
	return this->_chatStart;
}

/*bool Chat::user_Login()
{
	std::string password_h = "", login = "";
	bool result = false;
	char ch;
	while (true)
	{
		std::cout << "Введите логин: @";
		std::cin >> login;
		
		std::cout << "Введите пароль: ";
		std::cin >> password_h;
		std::cout << std::endl;

		if (this->login_and_password_comparison("@" + login, password_h))
		{
			this->_current_user_login = "@" + login;
			result = true;
			break;
		}
		else
		{
			std::cout << "Пользователь не существует, или введен неправильно логин (пароль) !!" << std::endl;
			std::cout << "Продолжить y/n: ";
			std::cin >> ch;

			if (ch == 'n')
				break;

		}
	}
	return result;
}*/

/*void Chat::chat_start_window()
{
	while (this->_chatStart && !this->_userExist)
	{
		int oper;

		std::cout << "Вход(1) | Регистрация(2) | Выход(0)" << std::endl;

		std::cout << ">>";
		std::cin >> oper;


		switch (oper)
		{
		case 1:
            Метод для входа зарегестрированного пользователя
			if (this->user_Login())
				this->_userExist = true;
			else
				this->_userExist = false;

			break;
		case 2:
            Регистрация пользователя
			if (this->user_Registration())
				this->_userExist = true;
			else
				this->_userExist = false;
			break;
		case 0:
            Выход
			this->_chatStart = false;
			break;
		default:
			break;
		}
	}
}*/

/*bool Chat::user_Registration()
{
	std::string last_name = "", name = "", patronymic = "", email = "", password_h = "", login = "";
	while (true)
	{
		std::cout << "Введите фамилию: ";
		std::cin >> last_name;

		std::cout << "Введите имя: ";
		std::cin >> name;

		std::cout << "Введите отчество: ";
		std::cin >> patronymic;

		std::cout << "Введите email: ";
		std::cin >> email;

		login = "@" + last_name + "_" + name;
		std::cout << "Логин по умолчанию = " << login << std::endl;

		std::cout << "Введите пароль: ";
		std::cin >> password_h;
		std::cout << std::endl;


        this->user =  new User(last_name, name, patronymic, email, password_h, login);

		this->checking_user_existence(user->getLogin(), user->getUserPassword());

		std::string list[] = {
			user->getLastName(),
			user->getName(),
			user->getPatronymic(),
			user->getEmail(),
			user->getLogin()
        };

		bool flag_clients = tables[0]->add_in_table(list);


		std::string list_2[] = {
			tables[0]->get_id_user(user->getLogin()),
			user->getUserPassword()
        };

		bool flag_h_p = tables[1]->add_in_table(list_2);
		
		if (flag_clients == true && flag_h_p == true)
		{
			this->_current_user_login = user->getLogin();
			return true;
			break;
		}

	}
	return false;
}*/

/*void Chat::chat_menu()
{
	char operation;

	std::cout << "Пользователь: " << this->get_currentUserLogin() << std::endl;

	while (this->_userExist)
	{
		std::cout << "(1)Входящие и отправленные сообщения | (2)Отправить сообщение | (3)Показать кто в чате | (0)Выйти ";

		std::cout << std::endl << ">> ";
		std::cin >> operation;

		switch (operation)
		{
		case '1':
			// входящие и отправленные сообщения
			this->incoming_and_sent_Messages();
			break;
		case '2':
			//Отправить сообщение
			this->send_Message();
			break;
		case '3':
			///Список зарегестрированных
			this->list_Users();
			break;
		case '0':
			//currentUser_ = nullptr;
			this->_userExist = false;
			break;
		default:
			//cout << "сделайте выбор.." << endl;
			break;
		}
	}
}*/

/*bool Chat::login_and_password_comparison(std::string login, std::string h_password)
{
	std::string h_p = this->user->get_hash_Login(h_password);

	std::string value_1 = tables[0]->get_id_user(login);
	std::string value_2 = tables[1]->get_id_user(h_p);

	if (value_1 == value_2 && value_1 != "-1" && value_2 != "-1")
		return true;

	return false;
}

const bool Chat::get_UserExist() const
{
	return this->_userExist;
}

const std::string Chat::get_currentUserLogin() const
{
	return this->_current_user_login;
}*/

/*void Chat::send_Message()
{
    std::string login_recipient,
           text_messages,
		   login_sender = this->get_currentUserLogin(); // login отправителя

	std::cout << "Кому отправить сообщение (введите login получателя): @";
	std::cin >> login_recipient;

	if (tables[0]->get_id_user("@" + login_recipient) == "-1") // проверка существования логина получателя
	{
		std::cout << "Не верный логин" << std::endl;
	}
	else
	{
		std::cout << "Сообщение: ";
		std::cin.ignore(); // игнорировать любые введенные посторонние символы
		std::getline(std::cin, text_messages); /// ввод текстового сообщения с пробелами

		//from - От
		//to - Кому
		this->messag = new Message(login_sender, "@" + login_recipient, text_messages);
		std::string list[] = {messag->getFrom(), messag->getTo(), messag->getText()};

		if (tables[2]->add_in_table(list) == true)
			std::cout << "Сообщение пользователю: " + messag->getTo() + " отправленно." << std::endl;
	}
}*/

/*void Chat::list_Users()
{
	std::string requests = "select clients.login from clients "
		"where clients.login != '" + this->get_currentUserLogin() + "'";

	auto list = tables[0]->request_select_from_Table(requests);

	if (list.size() > 0)
	{
		for (auto& item : list)
			std::cout << item << std::endl;
	}
	else
		std::cout << "Список пуст." << std::endl;
}*/

/*void Chat::incoming_and_sent_Messages()
{
	std::string request = "select sender_login, recipient_login, text_messag, date_send "
		"from messages where sender_login = '" + this->get_currentUserLogin() + "' OR recipient_login = '" + this->get_currentUserLogin() + "'";

	//cout << request << endl;

	auto list = tables[2]->request_select_from_Table(request);

	for (auto& item : list)
		std::cout << item << std::endl;
}

void Chat::checking_user_existence(std::string login, std::string h_password)
{
	std::string value_login = tables[0]->get_id_user(login);

	std::string value_h_p = tables[1]->get_id_user(h_password);

	std::string n_login, n_h_password;
	bool f_login = false, f_h_password = false, exist_Login = false, exist_h_password = false;

	if (value_login == "-1")
		exist_Login = true;
	
	if (value_h_p == "-1")
		exist_h_password = true;

	while (exist_Login == false || exist_h_password == false)
	{
		if (exist_Login == false)
		{
			f_login = false;
			std::cout << "Login уже существует, его нужно изменить. " << std::endl;
			std::cout << "Введите новый логин: @";
			std::cin >> n_login;
			user->setLogin("@" + n_login);

			//cout << " -> " << user->getLogin() << endl;

			f_login = true;
		}

		if (exist_h_password == false)
		{
			f_h_password = false;
			std::cout << "Пароль уже существует, его нужно изменить. " << std::endl;
			std::cout << "Введите новый пароль: ";
			std::cin >> n_h_password;
			user->setUserPassword(n_h_password);

			///cout << " -> " << user->getUserPassword() << endl;

			f_h_password = true;
		}

		if (f_login)
		{
			value_login = tables[0]->get_id_user(user->getLogin());
			if (value_login == "-1")
				exist_Login = true;
		}

		if (f_h_password)
		{
			value_h_p = tables[1]->get_id_user(user->getUserPassword());

			if (value_h_p == "-1")
				exist_h_password = true;
		}

	}
}*/
