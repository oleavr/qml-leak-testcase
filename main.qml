import QtQuick 2.2
import Badger 1.0

Rectangle {
    id: app

    width: 640
    height: 480
    color: 'orange'

    Text {
        id: progress
    }

    Component.onCompleted: {
        var count = 0;
        Badger.message.connect(function (message) {
            count++;
            progress.text = "callbacks: " + count;
            if (count % 10 === 0) {
                gc();
            }
            if (count === 100) {
                Qt.quit();
            }
        });
    }
}
