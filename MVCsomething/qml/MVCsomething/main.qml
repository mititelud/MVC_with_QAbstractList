import QtQuick 2.0
import QtMultimedia 5.0

Rectangle
{
    id: bgRect
    width: 800
    height: 600

    Text
    {
        id: txt2
        //anchors.centerIn: parent;
        x: 100+(parent.width-width)/2
        y: (parent.height)/2-20
        font.bold: true
    }

    Component
    {
        id: myDelegate
        Item
        {
            width: 200
            height: 40
            Rectangle
            {
                anchors.fill: parent
                anchors.margins: 2
                radius: 10
                color: "lightsteelblue"
                Row
                {
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter:  parent.verticalCenter
                    Text
                    {
                        id: frstname
                        text: " "+model.firstName
                        color: "black"
                    }
                }
                MouseArea
                {
                    anchors.fill: parent;
                    onClicked:
                    {
                        txt2.y=280
                        txt2.text=model.firstName;
                        myListView.currentIndex=index;
                        console.log(myListView.currentIndex)
                        pageLoader.y=-800
                    }
                }
            }
         }
    }

    Loader
    {
        id: pageLoader
        x: (parent.width-width)/2
        z:2
    }

    Rectangle
    {
        width: 200
        height: 40
        x:598
        color: "lightgrey"
        radius: 10
        y:2
        z:1
        Text
        {
            anchors.centerIn: parent
            text: "Add"
        }

        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                console.log("Add clicked")

                pageLoader.source = "add.qml"                                              //adding stuff

                txt2.y=-800
                pageLoader.y=0
            }
        }
    }


    Rectangle
    {
        width: 200
        height: 40
        x:598
        color: "lightgrey"
        radius: 10
        y:86
        z:1
        Text
        {
            anchors.centerIn: parent
            text: "Remove by lastname"
        }

        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                console.log("remove by lastname clicked")
                pageLoader.source = "removeLastname.qml"
                txt2.y=-800
                pageLoader.y=0
            }
        }
    }

    Rectangle
    {
        width: 200
        height: 40
        z:1
        color: "lightgrey"
        radius: 10
        x:598
        y:44

        Text
        {
            anchors.centerIn: parent
            text: "Delete"
        }

        MouseArea
        {
            anchors.fill: parent;
            onClicked:
            {
                console.log("Delete clicked")
                console.log(myListView.currentIndex)

                myModel.deleteItem(myListView.currentIndex)


                if( myListView.currentIndex==0)
                   myListView.currentIndex=0
                else  myListView.currentIndex-=1;
                pageLoader.y=-800;
                txt2.y=280
                txt2.text=txt2.text+" is deleted"
            }
        }
    }

    Rectangle
    {
        width: 200
        height: 40
        z:1
        color: "lightgrey"
        radius: 10
        x:598
        y:128

        Text
        {
            anchors.centerIn: parent
            text: "Sort"
        }

        MouseArea
        {
            anchors.fill: parent;
            onClicked:
            {
                console.log("sort clicked")
                console.log(myListView.currentIndex)

                myModel.sort()



//                pageLoader.y=-800;
  //              txt2.y=280
   //             txt2.text=txt2.text+" is deleted"
            }
        }
    }

    ListView
    {
        id: myListView
        anchors.fill: parent
        delegate: myDelegate
        model: myModel
        orientation: ListView.Vertical
        boundsBehavior: Flickable.StopAtBounds
    }
}
