module com.my.dziennik {
    requires javafx.controls;
    requires javafx.fxml;
    requires lombok;

    opens com.my.dziennik to javafx.fxml;
    exports com.my.model;
    exports com.my.dziennik;
}
