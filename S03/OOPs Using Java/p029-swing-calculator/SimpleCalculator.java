
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class SimpleCalculator extends JFrame {

    private JTextField displayField;
    private double num1, num2, result;
    private String operator;

    public SimpleCalculator() {
        setTitle("Simple Calculator");
        setSize(400, 150);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        displayField = new JTextField();
        displayField.setEditable(false);
        add(displayField, BorderLayout.NORTH);

        JPanel buttonPanel = new JPanel();
        add(buttonPanel, BorderLayout.CENTER);

        String[] buttons = {
            "7", "8", "9", "/",
            "4", "5", "6", "*",
            "1", "2", "3", "-",
            "0", ".", "=", "+",
            "C"
        };

        for (String text : buttons) {
            JButton button = new JButton(text);
            button.addActionListener(new ButtonClickListener());
            buttonPanel.add(button);
        }

        setVisible(true);
    }

    private class ButtonClickListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            String command = e.getActionCommand();

            if (command.equals("=")) {
                try {
                    num2 = Double.parseDouble(displayField.getText());
                    switch (operator) {
                        case "+":
                            result = num1 + num2;
                            break;
                        case "-":
                            result = num1 - num2;
                            break;
                        case "*":
                            result = num1 * num2;
                            break;
                        case "/":
                            if (num2 == 0) {
                                throw new ArithmeticException("Cannot divide by zero");
                            }
                            result = num1 / num2;
                            break;
                        default:
                            throw new IllegalStateException("Invalid operator");
                    }
                    displayField.setText(String.valueOf(result));
                } catch (Exception ex) {
                    displayField.setText("Error");
                }
            } else if (command.equals("C")) {
                displayField.setText("");
            } else if (command.equals("+") || command.equals("-") || command.equals("*") || command.equals("/")) {
                num1 = Double.parseDouble(displayField.getText());
                operator = command;
                displayField.setText("");
            } else {
                displayField.setText(displayField.getText() + command);
            }
        }
    }

    public static void main(String[] args) {
        SimpleCalculator calculator = new SimpleCalculator();
        calculator.setVisible(true);
    }
}
