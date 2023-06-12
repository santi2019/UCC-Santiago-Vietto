package edu.ucc.arqSoft.service.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.ResponseStatus;

import edu.ucc.arqSoft.service.dto.SensorRequestDto;
import edu.ucc.arqSoft.service.dto.SensorResponseDto;
import edu.ucc.arqSoft.service.model.Location;
import edu.ucc.arqSoft.service.service.SensorService;

@Controller
@RequestMapping("/sensor")
public class SensorController {

    @Autowired
    	private SensorService sensorService;

    @RequestMapping(value = "/{ID}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody ResponseEntity<Object> lookupSensorById(@PathVariable("ID") Long id) {
			SensorResponseDto dto = sensorService.getSensorById(id);
			return new ResponseEntity<Object>(dto, HttpStatus.OK);
	 }

    @RequestMapping(value = "/location/{LocationId}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody ResponseEntity<Object> lookupSensorsByLocation(@PathVariable("LocationId") Long locationId) {
			List<SensorResponseDto> dtos = sensorService.getSensorsByLocation(locationId);
			return new ResponseEntity<Object>(dtos, HttpStatus.OK);
	 }

    
    @RequestMapping(method = RequestMethod.POST, consumes = MediaType.APPLICATION_JSON_VALUE, produces = MediaType.APPLICATION_JSON_VALUE)
	@ResponseStatus(code = HttpStatus.CREATED)
	    public @ResponseBody SensorResponseDto registrar(@RequestBody SensorRequestDto request) {
		
		return sensorService.registrar(request);
		
	}


    @RequestMapping(value = "/", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody ResponseEntity<Object> getSensors() {
		
			List<SensorResponseDto> dtos = sensorService.getSensors();

			return new ResponseEntity<Object>(dtos, HttpStatus.OK);	
	 }


    @RequestMapping(value = "/toggle/{ID}", method = RequestMethod.PUT, produces = MediaType.APPLICATION_JSON_VALUE)
    	public @ResponseBody ResponseEntity<Object> turnOnSensorById(@PathVariable("ID") Long id) {
			SensorResponseDto dto = sensorService.toggle(id);
			return new ResponseEntity<Object>(dto, HttpStatus.OK);
	 }

}
