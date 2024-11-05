import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class ToFahrenheit extends JFrame {
    private final JTextField celsiusField;
    private final JLabel fahrenheitLabel;

    public ToFahrenheit() {
        setTitle("Celsius to Fahrenheit Converter");
        setSize(300, 150);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new FlowLayout());

        JLabel celsiusLabel = new JLabel("Celsius:");
        add(celsiusLabel);
        
        celsiusField = new JTextField(10);
        add(celsiusField);

        JButton convertButton = new JButton("Convert");
        add(convertButton);

        fahrenheitLabel = new JLabel("Fahrenheit: ");
        add(fahrenheitLabel);

        convertButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                convertTemperature();
            }
        });

        setVisible(true);
    }

    private void convertTemperature() {
        try {
            double celsius = Double.parseDouble(celsiusField.getText());

            double fahrenheit = (celsius * 9 / 5) + 32;

            fahrenheitLabel.setText("Fahrenheit: " + fahrenheit);
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(this, "Please enter a valid number", "Invalid Input", JOptionPane.ERROR_MESSAGE);
        }
    }

    public static void main(String[] args) {
        new ToFahrenheit();
    }
}
