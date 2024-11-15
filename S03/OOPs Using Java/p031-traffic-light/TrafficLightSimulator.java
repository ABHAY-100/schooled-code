import java.awt.*;
import javax.swing.*;

public class TrafficLightSimulator extends JFrame {
    private JPanel lightPanel;

    public TrafficLightSimulator() {
        setTitle("Traffic Light Simulator");
        setLayout(new BorderLayout());
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(400, 300);
        setLocationRelativeTo(null);

        lightPanel = new JPanel();
        lightPanel.setBackground(Color.GRAY);

        JRadioButton redButton = new JRadioButton("Red");
        JRadioButton yellowButton = new JRadioButton("Yellow");
        JRadioButton greenButton = new JRadioButton("Green");

        ButtonGroup group = new ButtonGroup();
        group.add(redButton);
        group.add(yellowButton);
        group.add(greenButton);

        JPanel buttonPanel = new JPanel();
        buttonPanel.add(redButton);
        buttonPanel.add(yellowButton);
        buttonPanel.add(greenButton);

        redButton.addActionListener(e -> lightPanel.setBackground(Color.RED));
        yellowButton.addActionListener(e -> lightPanel.setBackground(Color.YELLOW));
        greenButton.addActionListener(e -> lightPanel.setBackground(Color.GREEN));

        lightPanel.setBackground(Color.GRAY);

        add(lightPanel, BorderLayout.CENTER);
        add(buttonPanel, BorderLayout.SOUTH);
    }

    public static void main(String[] args) {
        TrafficLightSimulator simulator = new TrafficLightSimulator();
        simulator.setVisible(true);
    }
}
