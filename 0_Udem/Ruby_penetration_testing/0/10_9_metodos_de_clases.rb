
class Carro
  @marca = "Toyota"
  
  def self.marca
    @marca
  end

  def self.marca=(marca)      #   Carro.marca = "Tesla"
    @marca = marca
  end

  def self.x89p     #     Carro.x89p
    puts "Metodos de una classe/objeto"
  end

  def arrancar
    puts "Encendiendo..."
  end
  
end

Carro.marca = "Tesla"
Carro.x89p
puts "----------------------"
tesla = Carro.new
tesla.arrancar

####             class << self    'metodosDeLaClaseHERE'       end
class Carro
  def arrancar
    puts "Encendiendo..."
  end
  
  class << self
    def x89p     #     Carro.x89p
      puts "Metodos de una classe/objeto"
    end
    
    def marca
      @marca
    end

    def marca=(marca)      #   Carro.marca = "Tesla"
      @marca = marca
    end
  end

end

