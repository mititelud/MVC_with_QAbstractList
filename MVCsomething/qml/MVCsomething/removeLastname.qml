import QtQuick 2.0

Rectangle
{
    width: 200
    height: 200

    Text
    {
        anchors.centerIn: parent
        id: name
        text: "Remove object by name"
        font.bold: true
        y:(parent.height)/2+height+100
    }

    Text
    {
        x: parent.width/2-width-35
        y: (parent.height)/2+height
        id: firstName
        text: "Name: "
        font.bold: true
    }

    Rectangle
    {
        x: parent.width/2-25
        y: (parent.height)/2+height
        border.color: "lightgray"
        width: 140
        height: 16

        TextInput
        {
            id: inputl
            x: 1
            text: "PersonOBject.nr[]"
        }
    }

    Rectangle
    {
        width: parent.width-20
        height: 20
        radius:5
        y:140
        color: "lightgrey"
        x:10
        Text
        {
            id: namea
            anchors.centerIn: parent
            text: qsTr("Remove object")
        }

        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                console.log("remove object")
                myModel.deleteItemByLastname(inputl.text)
                inputl.text="PersonOBject.nr[]"
            }
        }
    }
}
