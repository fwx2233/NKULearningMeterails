#include"server.h"
#include"client.h"

// ���ֿɱ仯��ȫ������֧���Զ���
// �������˿ں�
u_short ServerPort = 12260;
// ������IP��ַ
char ServerIP[16];
// ���建������С
const int SBUF_SIZE = 2048;
// ������������
const int ListenMax = 5;
// ��ǰ���ӵ��û�����
int ConnectedNumber = 0;

// ȫ�ֱ�������
SOCKET ServerSocket;// sever�������������գ�client��������յ�������
SOCKET ClientSockets[ListenMax];
SOCKADDR_IN ServerAddr;// �������IP��ַ�Ͷ˿�
SOCKADDR_IN ClientAddrs[ListenMax];
HANDLE ClientThreads[ListenMax];

int snaddr = sizeof(SOCKADDR_IN);
char SsendBuf[SBUF_SIZE];// ���ͻ�����
char SinputBuf[SBUF_SIZE];// ���뻺����
char SrecvBuf[SBUF_SIZE];//�������ݻ�����
char hello[] = "Connected! Welcome to our char room.\0";
char errorMessage[] = "Input destination user error, please check your input.\nPlease use 'getUsrList' to get users.\0";

struct para {
	int number;
	int len;
	char name[20];
	bool used = false;
};
para ClientInformation[ListenMax];

int getPort() {
	cout << "Please input your port to connect with others which is in range(12000,16000).\n";
	cout << "If you wanna use default port, please input 0\n";
	u_short tempPort;
	cin >> tempPort;
	while (tempPort < 12000 || tempPort>16000) {
		if (tempPort == 0) {
			return ServerPort;
		}
		cout << "Invalid input. Please input in range(12000,16000) or 0.\n";
		cin >> tempPort;
	}
	return tempPort;
}

void getServerIP(char* p) {
	cout << "Please use 'ipconfig' to get your ip and input\n";
	char ip[16];
	cin.getline(ip, sizeof(ip));
	int index = 0;
	while (ip[index] != '\0') {
		p[index] = ip[index];
		index++;
	}
}

bool isName(char* a) {
	if (a[0] == 'n')
		return true;
	else
		return false;
}

bool sisClientQuit(char* a) {
	int nameLen1 = int(a[25]);
	int nameLen2 = int(a[25 + nameLen1 + 1]);
	int len = 0;
	while (a[len] != '\0')
		len++;
	if ((len == (25 + 1 + nameLen1 + 1 + nameLen2 + 4)) && a[25 + 1 + nameLen1 + 1 + nameLen2] == 'q' && a[25 + 1 + nameLen1 + 1 + nameLen2 + 1] == 'u' && a[25 + 1 + nameLen1 + 1 + nameLen2 + 2] == 'i' && a[25 + 1 + nameLen1 + 1 + nameLen2 + 3] == 't')
		return true;
	else
		return false;
}

bool isSameStr(char* a, char* b) {
	int i = 0;
	bool flag = true;
	while (a[i] != '\0' && b[i] != '\0') {
		if (a[i] != b[i]) {
			flag = false;
			break;
		}
		i++;
	}
	if (a[i] != '\0' || b[i] != '\0')
		flag = false;
	return flag;
}

bool isGetList(char* a) {
	const char* sample = "getUsrList\0";
	if (!strcmp(sample, a))
		return true;
	else
		return false;
}

DWORD WINAPI recvMessage(LPVOID tempPara) {
	para* p = (para*)tempPara;
	int num = p->number;
	while (1) {
		//memset(SrecvBuf, 0, SBUF_SIZE);
		if (recv(ClientSockets[num], SrecvBuf, SBUF_SIZE, 0) < 0) {
			//cout << "Connect failed. Error code is " << SOCKET_ERROR << ".\n";
		}
		else {
			if (isGetList(SrecvBuf)) {
				char usrList[SBUF_SIZE];
				memset(usrList, 0, SBUF_SIZE);
				usrList[0] = 'u';
				int posi = 1;
				for (int tempIndex = 0; tempIndex < ListenMax; tempIndex++) {
					if (ClientInformation[tempIndex].used) {
						usrList[posi] = char(ClientInformation[tempIndex].len);
						posi += 1;
						strcat(usrList, ClientInformation[tempIndex].name);
						posi += ClientInformation[tempIndex].len;
					}
				}
				send(ClientSockets[num], usrList, sizeof(usrList), 0);
			}
			else {
				if (SrecvBuf[0]=='q') {
					int len = int(SrecvBuf[1]);
					char* nameString = new char[len + 1];
					for (int index=0; index < len; index++)
						nameString[index] = SrecvBuf[index+2];
					nameString[len] = '\0';
					cout << "�û�: " << nameString << " ������.\n";
					ConnectedNumber -= 1;
					cout << "��ǰ�û�����Ϊ " << ConnectedNumber << "\n";
					// ����ǰ���ߵ�ÿ���ͻ�����һ����Ϣ�������Լ���
					for (int i = 0; i < ListenMax; i++) {
						if (i == num || ClientSockets[i] == INVALID_SOCKET)
							continue;
						else
							send(ClientSockets[i], SrecvBuf, sizeof(SrecvBuf), 0);
					}
					closesocket(ClientSockets[num]);
					ClientInformation[num].used = false;
					break;
				}
				else {
					// ���·�װ��Ϣ
					char timeString[26];
					int index = 0;
					for (; index < 25; index++)
						timeString[index] = SrecvBuf[index];
					timeString[25] = '\0';
					int len = int(SrecvBuf[index]);
					index += 1;
					char* dstName = new char[len + 1];
					for (; index < 26 + len; index++)
						dstName[index - 26] = SrecvBuf[index];
					dstName[len] = '\0';
					len = int(SrecvBuf[index]);
					index += 1;
					int lastPosi = len + index;
					int nowPost = index - 1;
					char* srcNameString = new char[len + 2];
					srcNameString[0] = char(len);
					for (; index < lastPosi; index++)
						srcNameString[index - nowPost] = SrecvBuf[index];
					srcNameString[len + 1] = '\0';
					
					char tempBuf[SBUF_SIZE];
					len = 0;
					char mess[SBUF_SIZE];
					while (SrecvBuf[index] != '\0') {
						mess[len] = SrecvBuf[index];
						len++;
						index++;
					}
					mess[len] = '\0';
					memset(tempBuf, 0, SBUF_SIZE);
					strcat(tempBuf, timeString);
					strcat(tempBuf, srcNameString);
					strcat(tempBuf, mess);

					// ���͸���Ӧ���û�
					int dst = 0;
					for (; dst < ListenMax; dst++) {
						if (ClientInformation[dst].used) {
							if (isSameStr(ClientInformation[dst].name, dstName)) {
								// ������Ϣ
								send(ClientSockets[ClientInformation[dst].number], tempBuf, sizeof(tempBuf), 0);
								break;
							}
						}
					}
					if (dst == ListenMax) {
						send(ClientSockets[ClientInformation[dst].number], errorMessage, sizeof(tempBuf), 0);
					}
				}
			}
		}
	}
	return 0;
}

int serverMain() {

	// ����socket��
	WSADATA wsadata;
	if (WSAStartup(MAKEWORD(2, 2), &wsadata)) {
		//������س�����ͣ�������������Ϣ
		cout << "����socketʧ��\n";
		system("pause");
		return -1;
	}

	// ����socket������˳��:IPV4����ʽ�׽��֣�ָ��Э��
	ServerSocket = socket(AF_INET, SOCK_STREAM, 0);

	// ��ʼ����ַ��Ϣ
	// inet_addr������IP��ַת���������ֽ���
	ServerAddr.sin_family = AF_INET;
	getServerIP(ServerIP);
	inet_pton(AF_INET, ServerIP, &ServerAddr.sin_addr.S_un.S_addr);
	ServerPort = 12260; // ServerPort = getPort();
	//cin.get();
	ServerAddr.sin_port = htons(ServerPort);

	// ��socket�͵�ַ
	bind(ServerSocket, (SOCKADDR*)&ServerAddr, sizeof(SOCKADDR));

	cout << "Server start success. Your Server IP is: " << ServerIP << "\tYour port is: " << ServerPort << endl;
	
	// ��ʼѭ������
	while (1) {
		if (ConnectedNumber == 0)
			cout << "Witing for connection......\n";
		// ���ö��г���Ϊ5
		listen(ServerSocket, ListenMax);

		// accept���������󣬲���һ��socket����´�����socket
		int i = 0;
		for (; i < ListenMax; i++)
			if (ClientSockets[i] == 0)
				break;
		ClientSockets[i] = accept(ServerSocket, (SOCKADDR*)&ClientAddrs[i], &snaddr);
		// ����´�����socket�Ƿ���Ч
		if (ClientSockets[i] != INVALID_SOCKET) {
			ClientInformation[i].number = i;
			// ���ӳɹ�
			ConnectedNumber += 1;
			cout << "�ͻ������ӳɹ�����ǰ�û�����Ϊ��" << ConnectedNumber << endl;

			memset(SrecvBuf, 0, SBUF_SIZE);
			recv(ClientSockets[i], SrecvBuf, SBUF_SIZE, 0);
			if (isName(SrecvBuf)) {
				ClientInformation[i].len = int(SrecvBuf[1]);
				int indexOfName = 2;
				while (SrecvBuf[indexOfName] != '\0') {
					ClientInformation[i].name[indexOfName - 2] = SrecvBuf[indexOfName];
					indexOfName++;
				}
				ClientInformation[i].name[int(SrecvBuf[1]) + 1] = '\0';
				ClientInformation[i].used = true;
				cout << "usr: " << ClientInformation[i].name << endl;
			}
			// ���߿ͻ������ӳɹ�
			// ��ȡ��ǰʱ��
			time_t now = time(0);
			// ת�����ַ�����ʽ
			char* dt = ctime(&now);
			memset(SsendBuf, 0, SBUF_SIZE);
			strcat(SsendBuf, dt);
			strcat(SsendBuf, hello);
			send(ClientSockets[i], SsendBuf, SBUF_SIZE, 0);
			//delete[] dt;
			memset(SsendBuf, 0, SBUF_SIZE);
			ClientThreads[i] = CreateThread(NULL, NULL, recvMessage, &ClientInformation[i], 0, NULL);
			
			if (ClientThreads[i] == 0) {
				cout << "Cteate thread failed. Execution stop.\n";
				ConnectedNumber -= 1;
				return -1;
			}
		}
		else {
			cout << "Connect failed.\n";
		}
	}

	closesocket(ServerSocket);

	WSACleanup();
	cout << "Server power off.\n";
	return 0;
}