import QtQuick 2.0

Rectangle
{
    width: 200
    height: 200

    Text
    {
        anchors.centerIn: parent
        id: name
        text: "Add new object"
        font.bold: true
    }

    Text
    {
        x: parent.width/2-width-20
        y: (parent.height)/2+height
        id: firstName
        text: "Firstname: "
        font.bold: true
    }

    Rectangle
    {
        x: parent.width/2-10
        y: (parent.height)/2+height
        border.color: "lightgray"
        width: 140
        height: 16
        TextInput
        {
            id:inputf
            x:1
            text: "PersonOBject.nr[]"
        }
    }

    Rectangle
    {
        width: parent.width-20
        height: 20
        radius:5
        y:140
        x:20
        color: "lightgrey"



        Text
        {
            id: namea
            anchors.centerIn: parent
            text: qsTr("Add object")
        }

        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                console.log("add object")
                myModel.addItem(inputf.text)
                inputf.text="PersonOBject.nr[]"
            }
        }
    }
}
