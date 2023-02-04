import javax.swing.*;
import java.awt.*;

public class TestGUI {
    public static void main(String[] args) {
        JFrame frame = new JFrame("TestGUI");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JPanel panel = new JPanel();
        frame.add(panel);
        frame.setSize(300,300);
        frame.setVisible(true);
    }
}
