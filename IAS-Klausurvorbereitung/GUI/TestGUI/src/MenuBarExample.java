import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MenuBarExample {
    public static void main(String[] args) {
        JFrame frame = new JFrame("JMenuBar Example");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JMenuBar menuBar = new JMenuBar();
        frame.setJMenuBar(menuBar);

        JMenu fileMenu = new JMenu("Datei");
        menuBar.add(fileMenu);

        JMenuItem newItem = new JMenuItem("Neu");
        fileMenu.add(newItem);

        JMenuItem openItem = new JMenuItem("Öffnen");
        fileMenu.add(openItem);

        JMenuItem exitItem = new JMenuItem("Beenden");
        exitItem.addActionListener(e -> System.exit(0));
        fileMenu.add(exitItem);

        JMenu editMenu = new JMenu("Bearbeiten");
        menuBar.add(editMenu);

        JMenuItem cutItem = new JMenuItem("Ausschneiden");
        editMenu.add(cutItem);

        JMenuItem copyItem = new JMenuItem("Kopieren");
        editMenu.add(copyItem);

        JMenuItem pasteItem = new JMenuItem("Einfügen");
        editMenu.add(pasteItem);

        frame.setSize(400, 300);
        frame.setVisible(true);
    }
}
