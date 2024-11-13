import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class Calculator extends JFrame {
    private final JTextField displayArea;
    private double num1, num2, result;
    private String operator;

    Calculator() {
        setTitle("Simple Calculator"); 
        setSize(300, 160);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        displayArea = new JTextField();
        displayArea.setEditable(false);
        add(displayArea, BorderLayout.NORTH);

        JPanel btnPanel = new JPanel();
        add(btnPanel, BorderLayout.CENTER);

        String[] buttons = {
            "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "+", "-", "*", "/", "C", "="
        };

        for (String text : buttons) {
            JButton button = new JButton(text);
            button.addActionListener(new btnListner());
            btnPanel.add(button);
        }

        setVisible(true);
    }

    private class btnListner implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent event) {
            String command = event.getActionCommand();

            if (command.equals("=")) {
                num2 = Double.parseDouble(displayArea.getText());

                try {
                    switch (operator) {
                        case "+" : 
                            result = num1 + num2;
                            break;
                        case "-" : 
                            result = num1 - num2;
                            break;
                        case "*" : 
                            result = num1 * num2;
                            break;
                        case "/" : 
                            if (num2 == 0) {
                                throw new ArithmeticException("Division by 0 not possible");
                            }
                            result = num1 / num2;
                            break;
                        default :
                            throw new IllegalStateException("Invalid Operator");
                    }
                    displayArea.setText(String.valueOf(result));
                } catch (Exception e) {
                    displayArea.setText("Error");
                }
            } else if (command.equals("C")) {
                displayArea.setText("");
            } else if (command.equals("+") || command.equals("-") || command.equals("*") || command.equals("/")) {
                num1 = Double.parseDouble(displayArea.getText());
                operator = command;
                displayArea.setText("");
            } else {
                displayArea.setText(displayArea.getText() + command);
            }
        }
    }

    public static void main(String args[]) {
        new Calculator();
    }
}
