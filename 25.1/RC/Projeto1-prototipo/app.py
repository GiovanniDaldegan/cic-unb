from flask import Flask, render_template
from flask_socketio import SocketIO, emit, send

app = Flask(__name__)
app.config["SECRET_KEY"] = "secret!"
socketio = SocketIO(app)

class Message:
    def __init__(self, author:str, content, timeStamp:int=None):
        self.author = author
        self.content = content
        self.timeStamp = timeStamp


class Client:
    def __init__(self, name:str):
        self.id = "12345"
        self.name = name


class ChatRoom:
    def __init__(self, name:str):
        self.id = "id0"
        self.name = name
        self.clients = []
        self.messages = []

    def addClient(self, client:Client):
        self.clients.append(client)

    def removeClient(self, client_id):
        client_index = -1
        for client_index in range(self.clients):
            if self.clients[client_index].id == client_id:
                break
        self.clients.pop(client_index)

    def addMessage(self, message:Message):
        self.messages.append(message)


chatrooms : dict[str, ChatRoom]
clients : dict[str, Client]


def getClient(client_id:str) -> Client:
    return clients[client_id]

def getChatRoom(room_id:str) -> ChatRoom:
    return chatrooms[room_id]

def listRooms() -> list[tuple[str, int]]:
    roomInfo = []
    for room in chatrooms.values():
        roomInfo.append( (room.name, len(room.clients)) )
    return roomInfo


@app.route("/")
def index():
    return render_template("index.html")

#@app.route("/salas")
#def 

#@app.route("/salas/<room>") ??
#def 

@socketio.on("register")
def register_client(data):
    newClient = Client(data["name"])
    clients[newClient.id] = newClient

    emit("get_rooms", listRooms())
    print(f"\"{newClient.name}\" foi registrado!")


@socketio.on("create_room")
def createRoom(data):
    newRoom = ChatRoom(data["name"])
    chatrooms[newRoom.id] = newRoom

    emit("get_rooms", listRooms())
    print(f"Sala \"{newRoom.name}\" criada!")


@socketio.on("enter_room")
def load_room(data):
    getChatRoom(data["room_id"]).addClient(getClient(data["client_id"]))

    emit("load_room", {"n_clients" : len(getChatRoom(data["room_id"])["clients"]),
                       "chatHistory" : getChatRoom(data["room_id"])["messages"]})
    print(f"\"{getClient(data["client_id"])}\" entrou na sala \"{getChatRoom(data["room_id"])}\"")


@socketio.on("leave_room")
def leave_room(data):
    getChatRoom(data["room_id"]).removeClient(getClient(data["client_id"]))

    emit("get_rooms", listRooms())
    print(f"\"{getClient(data["client_id"])}\" saiu da sala \"{getChatRoom(data["room_id"])}\"")



@socketio.on("send_message")
def on_client_message(data):
    getChatRoom(data["room_id"]).addMessage(data["message"])
    
    # TODO: send to all clients in chatroom
    emit("get_message", data["message"], broadcast=True)
    print(f"\"{getClient(data["client_id"])}\"")

if __name__ == "__main__":
    socketio.run(app)#, debug=True)
