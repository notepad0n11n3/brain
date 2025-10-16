
class Panda8hat


  attr_accessor :minutes, :title
  def initialize(title)
    self.title = title
  end


end

des_des=Panda8hat.new("jugando con initialize <3")
puts des_des.title
