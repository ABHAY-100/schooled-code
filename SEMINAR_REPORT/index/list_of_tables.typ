#set page(
  paper: "a4",
  margin: (left: 1.5cm, right: 1.5cm, top: 3.5cm, bottom: 3.5cm)
)

#set text(
  font: "New Computer Modern",
  size: 13pt
)

#set par(
  justify: true,
  leading: 0.7em
)

#align(center)[
  #text(size: 21pt, weight: "bold")[List of Tables]
]

#v(1.4cm)

#outline(
  title: none,
  target: figure.where(kind: table),
  indent: auto,
)