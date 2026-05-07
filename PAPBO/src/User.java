import java.util.ArrayList;

public abstract class User {

    protected String username;
    protected String password;

    public User(String username, String password) {
        this.username = username;
        this.password = password;
    }

    public abstract void menu(ArrayList<Booth> dataBooth,
                              ArrayList<Penyewaan> dataSewa);
}