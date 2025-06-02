from flask import Flask, render_template
from flask_socketio import SocketIO, emit, send

app = Flask(__name__)
app.config["SECRET_KEY"] = "secret!"
socketio = SocketIO(app)

class Message:
    def __init__(self, author:str, content, timeStamp=None):
        self.author = author
        self.content = content
        self.timeStamp = timeStamp


class Client:
    def __init__(self, name:str):
        self.id = "12345"
        self.name :str = name
        self.room_id = ""

class ChatRoom:
    def __init__(self, name:str):
        self.id = "id0"
        self.name :str = name
        self.clients = [] # elemento deve ser uma referência a elemento de clients
        self.messages : list[Message] = []

    def addClient(self, client:Client):
        self.clients.append(client)

    def removeClient(self, client_id):
        client_index = -1
        for client_index in range(len(self.clients)):
            if self.clients[client_index].id == client_id:
                break
        self.clients.pop(client_index)

    def addMessage(self, message:Message):
        self.messages.append(message)


chatrooms :dict[str, ChatRoom] = {}
clients :dict[str, Client] = {}


def getClient(client_id:str) -> Client:
    return clients[client_id]

def getChatRoom(room_id:str) -> ChatRoom:
    return chatrooms[room_id]

def listRooms() -> list[tuple[str, int]]:
    roomInfo = []
    for room in chatrooms.values():
        roomInfo.append( (room.name, len(room.clients)) )
    return roomInfo

def getRoomInfo(room_id):
    room = getChatRoom(room_id)
    return {
        "name" : room.name,
        "clients" : [i.name for i in room.clients],
        "messages" : room.messages
    }

def emitGetRooms():
    emit("get_rooms", listRooms())

# TEMP
def printROOOOMS():
    for i in chatrooms.values():
        print("> ", i.name)
        for j in i.clients:
            print("  -", j.name)


@app.route("/")
def index():
    return render_template("index.html")

#@app.route("/salas")
#def 

#@app.route("/salas/<room>") ??
#def 

@socketio.on("register")
def register_client(data):
    newClient = Client(data["client_name"])
    clients[newClient.id] = newClient

    emitGetRooms() # TODO: checar se manda apenas para o cliente específico
    print(f"\"{newClient.name}\" foi registrado!")


@socketio.on("create_room")
def createRoom(data):
    # TODO: criar sala somente se não houver outra com o nome escolhido
    newRoom = ChatRoom(data["room_name"])
    chatrooms[newRoom.id] = newRoom

    emitGetRooms()
    print(f"Sala \"{newRoom.name}\" criada!")
    printROOOOMS()


@socketio.on("delete_room")
def deleteRoom(data):
    # TODO: deletar sala somente se ela existir e não houver clientes nela
    name = getChatRoom(data["room_id"]).name
    del chatrooms[data["room_id"]]

    emitGetRooms()
    print(f"Sala \"{name}\" deletada")
    printROOOOMS()


@socketio.on("enter_room")
def load_room(data):
    # TODO: entrar em sala somente se ela existir e cliente não estiver em nenhuma sala
    # TODO: determinar o id do client pela sua conexão, o socketio deve fornecer algo assim
    getChatRoom(data["room_id"]).addClient(getClient("12345")) #getClient(data["client_id"])) 
    getClient("12345").room_id = data["room_id"]

    emit("load_room", getRoomInfo(data["room_id"]))
    print(f"\"{getClient("12345").name}\" entrou na sala \"{getChatRoom(data["room_id"]).name}\"")
    printROOOOMS()


@socketio.on("leave_room")
def leaveRoom(data):
    # TODO: sair da sala somente se sala existir e o cliente estiver nela
    # getChatRoom(getClient("CLIENTE Q ATIVOU EVENTO").room_id).removeClient()
    client = getClient("12345")
    getChatRoom(client.room_id).removeClient(client.id)

    emitGetRooms()
    print(f"\"{client.name}\" saiu da sala \"{getChatRoom(client.room_id)}\"")
    getClient(client.id).room_id = "" # client.leaveRoom()
    printROOOOMS()


@socketio.on("send_message")
def onClientMessage(data):
    # TODO: 
    getChatRoom(data["room_id"]).addMessage(data["message"])

    # TODO: send to all clients in chatroom
    emit("get_message", data["message"], broadcast=True)
    print(f"\"{getClient(data["client_id"])}\"")

if __name__ == "__main__":
    socketio.run(app, debug=True) # type: ignore
