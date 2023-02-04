import javax.swing.*;
import java.awt.*;

public class InternalFrameExample {
    public static void main(String[] args) {
        JFrame frame = new JFrame("JInternalFrame Example");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container content = frame.getContentPane();
        content.setLayout(new BorderLayout());

        JDesktopPane desktopPane = new JDesktopPane();
        content.add(desktopPane, BorderLayout.CENTER);

        JInternalFrame internalFrame = new JInternalFrame("Titel", true, true, true, true);
        internalFrame.setSize(400, 300);
        internalFrame.setLocation(50, 50);
        internalFrame.add(new JLabel("Inhalt des internen Fensters"));
        desktopPane.add(internalFrame);
        internalFrame.setVisible(true);

        frame.setSize(600, 400);
        frame.setVisible(true);
    }
}
